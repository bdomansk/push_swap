/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_rotates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:31:49 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/24 15:31:51 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int			ft_tpb(t_stack *b, int num)
{
	int		len;
	int		max;

	max = ft_max_with_limit(b, num, &len);
	return (len);
}

static int			ft_get_min(t_rotates *rotates)
{
	int	min;

	if (rotates->ra + rotates->rrb < rotates->rra + rotates->rb)
	{
		rotates->type = 1;
		min = rotates->ra + rotates->rrb;
	}
	else
	{
		rotates->type = 2;
		min = rotates->rra + rotates->rb;
	}
	if (rotates->ra + rotates->rb - rotates->rr < min)
	{
		rotates->type = 3;
		min = rotates->ra + rotates->rb - rotates->rr;
	}
	if (rotates->rra + rotates->rrb - rotates->rrr < min)
	{
		rotates->type = 4;
		min = rotates->rra + rotates->rrb - rotates->rrr;
	}
	return (min);
}

static t_rotates	*ft_get_rotates(int num, t_stack *a, t_stack *b)
{
	t_rotates	*rotates;
	t_stack		*temp;

	rotates = (t_rotates*)malloc(sizeof(t_rotates));
	temp = a;
	rotates->ra = 0;
	while (temp->num != num)
	{
		rotates->ra++;
		temp = temp->next;
	}
	rotates->rra = ft_lstlen(a) - rotates->ra;
	rotates->rb = ft_tpb(b, num);
	rotates->rrb = ft_lstlen(b) - rotates->rb;
	rotates->rr = (rotates->ra > rotates->rb) ? rotates->rb : rotates->ra;
	rotates->rrr = (rotates->rra > rotates->rrb) ? rotates->rrb : rotates->rra;
	rotates->min = 0;
	rotates->type = 0;
	rotates->min = ft_get_min(rotates);
	return (rotates);
}

t_rotates			*ft_min_rotates(t_stack *a, t_stack *b)
{
	t_stack		*temp;
	t_rotates	*rotates;
	t_rotates	*min_rotates;

	temp = a;
	rotates = ft_get_rotates(temp->num, a, b);
	min_rotates = rotates;
	while (temp)
	{
		rotates = ft_get_rotates(temp->num, a, b);
		if (rotates->min < min_rotates->min)
		{
			free(min_rotates);
			min_rotates = rotates;
		}
		else
			free(rotates);
		temp = temp->next;
	}
	return (min_rotates);
}
