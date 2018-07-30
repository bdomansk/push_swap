/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sorts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:52:19 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/06 15:52:22 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_cmd	*ft_sort3_1(t_stack *a, t_stack *b, t_ps_flags *fl, int *n)
{
	t_cmd *cmd;

	cmd = NULL;
	if (n[0] < n[1] && n[1] > n[2] && n[2] > n[0])
	{
		cmd = ft_comnd(&a, &b, fl, "rra\n");
		cmd->next = ft_comnd(&a, &b, fl, "sa\n");
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[2] < n[0])
		cmd = ft_comnd(&a, &b, fl, "rra\n");
	else if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		cmd = ft_comnd(&a, &b, fl, "sa\n");
	else if (n[0] > n[1] && n[1] < n[2] && n[2] < n[0])
		cmd = ft_comnd(&a, &b, fl, "ra\n");
	else if (n[0] > n[1] && n[1] > n[2] && n[2] < n[0])
	{
		cmd = ft_comnd(&a, &b, fl, "ra\n");
		cmd->next = ft_comnd(&a, &b, fl, "sa\n");
	}
	return (cmd);
}

static t_cmd	*ft_sort3_2(t_stack *a, t_stack *b, t_ps_flags *fl, int *n)
{
	t_cmd *cmd;

	cmd = NULL;
	if (n[0] < n[1] && n[1] < n[2] && n[2] > n[0])
	{
		cmd = ft_comnd(&a, &b, fl, "rb\n");
		cmd->next = ft_comnd(&a, &b, fl, "sb\n");
	}
	else if (n[0] < n[1] && n[1] > n[2] && n[2] > n[0])
		cmd = ft_comnd(&a, &b, fl, "rb\n");
	else if (n[0] < n[1] && n[1] > n[2] && n[2] < n[0])
		cmd = ft_comnd(&a, &b, fl, "sb\n");
	else if (n[0] > n[1] && n[1] < n[2] && n[2] > n[0])
		cmd = ft_comnd(&a, &b, fl, "rrb\n");
	else if (n[0] > n[1] && n[1] < n[2] && n[2] < n[0])
	{
		cmd = ft_comnd(&a, &b, fl, "rrb\n");
		cmd->next = ft_comnd(&a, &b, fl, "sb\n");
	}
	return (cmd);
}

t_cmd			*ft_sort3(t_stack *a, t_stack *b, int asc, t_ps_flags *fl)
{
	int		num[3];
	t_stack	*temp;
	t_stack *next;

	temp = (asc) ? a : b;
	num[0] = temp->num;
	next = temp->next;
	num[1] = next->num;
	next = next->next;
	num[2] = next->num;
	if (asc)
		return (ft_sort3_1(a, b, fl, num));
	else
		return (ft_sort3_2(a, b, fl, num));
}

t_cmd			*ft_sort2(t_stack *a, t_stack *b, int asc, t_ps_flags *fl)
{
	t_stack *next;

	if (asc)
	{
		next = a->next;
		if (a->num > next->num)
			return (ft_comnd(&a, &b, fl, "sa\n"));
	}
	else
	{
		next = b->next;
		if (b->num < next->num)
			return (ft_comnd(&a, &b, fl, "sb\n"));
	}
	return (NULL);
}
