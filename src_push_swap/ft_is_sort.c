/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:46:30 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/11 12:46:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ft_stackcpy(t_stack *s)
{
	t_stack *cpy;

	cpy = (t_stack*)malloc(sizeof(t_stack));
	cpy->num = s->num;
	if (s->next)
		cpy->next = ft_stackcpy(s->next);
	else
		cpy->next = NULL;
	return (cpy);
}

int				ft_is_partly_sort(t_stack *s, int asc)
{
	t_stack *temp;
	int		len;

	len = ft_lstlen(s) + 1;
	temp = ft_stackcpy(s);
	while (len >= 0)
	{
		if (ft_is_sort(temp, asc))
		{
			ft_free_stack2(temp);
			return (1);
		}
		ft_rotate(temp);
		len--;
	}
	ft_free_stack2(temp);
	return (0);
}

int				ft_is_sort(t_stack *stack, int asc)
{
	t_stack *temp;
	t_stack *next;

	temp = stack;
	while (temp)
	{
		next = temp->next;
		if (next && ((next->num < temp->num && asc)
		|| (next->num > temp->num && !asc)))
			return (0);
		temp = temp->next;
	}
	return (1);
}
