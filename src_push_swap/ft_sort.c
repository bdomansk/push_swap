/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 12:43:39 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/10 12:43:41 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cmd	*ft_gototheend(t_cmd *cmd)
{
	t_cmd *temp;

	temp = cmd;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_cmd	*ft_rotate_stack_a(t_stack **a, t_stack **b, t_ps_flags *fl)
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
	min = ft_find_min(*a, &length);
	command = (length > (ft_lstlen(*a) / 2)) ? "rra\n" : "ra\n";
	while (min != (*a)->num)
	{
		cmd->next = ft_comnd(a, b, fl, command);
		cmd = cmd->next;
	}
	return (begin);
}

t_cmd	*ft_prepare_pa(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;
	int		len;
	char	*command;
	int		min;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	len = 0;
	min = ft_min_with_limit(*a, (*b)->num, &len);
	command = (len < ft_lstlen(*a) / 2) ? "ra\n" : "rra\n";
	while (min != (*a)->num)
	{
		cmd->next = ft_comnd(a, b, fl, command);
		cmd = cmd->next;
	}
	cmd->next = ft_comnd(a, b, fl, "pa\n");
	return (begin);
}

t_cmd	*ft_sort_stacks(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	while (!ft_is_partly_sort(*a, 1))
	{
		cmd->next = ft_push_stack_a(a, b, fl);
		cmd = ft_gototheend(cmd);
	}
	while (ft_lstlen(*b) > 0)
	{
		cmd->next = ft_prepare_pa(a, b, fl);
		cmd = ft_gototheend(cmd);
	}
	cmd->next = ft_rotate_stack_a(a, b, fl);
	return (begin);
}

t_cmd	*ft_sort(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd	*cmd;
	t_cmd	*begin;

	if (ft_is_sort(*a, 1))
		return (NULL);
	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	if (ft_lstlen(*a) == 2)
		cmd->next = ft_sort2(*a, *b, 1, fl);
	else if (ft_lstlen(*a) == 3)
		cmd->next = ft_sort3(*a, *b, 1, fl);
	else if (ft_lstlen(*a) <= 10)
		cmd->next = ft_mini_sort(a, b, fl);
	else
		cmd->next = ft_sort_stacks(a, b, fl);
	return (begin);
}
