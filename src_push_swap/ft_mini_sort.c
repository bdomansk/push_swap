/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:16:50 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/24 16:16:52 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cmd	*ft_last_push(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	while (ft_lstlen(*b) > 0)
	{
		cmd->next = ft_comnd(a, b, fl, "pa\n");
		cmd = cmd->next;
	}
	return (begin);
}

t_cmd	*ft_push_min(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;
	int		length;
	int		min;
	char	*command;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	while (!ft_is_partly_sort(*a, 1) && ft_lstlen(*a) > 3)
	{
		min = ft_find_min(*a, &length);
		command = (2 * (length - 1) < ft_lstlen(*a)) ? "ra\n" : "rra\n";
		while (min != (*a)->num)
		{
			cmd->next = ft_comnd(a, b, fl, command);
			cmd = cmd->next;
		}
		cmd->next = ft_comnd(a, b, fl, "pb\n");
		cmd = cmd->next;
	}
	return (begin);
}

t_cmd	*ft_mini_sort(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	cmd->next = ft_push_min(a, b, fl);
	cmd = ft_gototheend(cmd);
	if (ft_lstlen(*a) == 2)
		cmd->next = ft_sort2(*a, *b, 1, fl);
	else if (ft_lstlen(*a) == 3)
		cmd->next = ft_sort3(*a, *b, 1, fl);
	else if (ft_is_partly_sort(*a, 1))
		cmd->next = ft_rotate_stack_a(a, b, fl);
	cmd = ft_gototheend(cmd);
	cmd->next = ft_last_push(a, b, fl);
	return (begin);
}
