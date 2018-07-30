/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comnd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 13:47:33 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/06 13:47:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_cmd	*ft_new_cmd(char *command)
{
	t_cmd *new;

	new = (t_cmd*)malloc(sizeof(t_cmd));
	new->command = command;
	new->next = NULL;
	return (new);
}

static t_cmd	*ft_comnd2(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp(command, "rb\n") == 0)
		ft_rotate(*b);
	else if (ft_strcmp(command, "rr\n") == 0)
	{
		ft_rotate(*a);
		ft_rotate(*b);
	}
	else if (ft_strcmp(command, "rra\n") == 0)
		ft_reverse_rotate(*a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		ft_reverse_rotate(*b);
	else if (ft_strcmp(command, "rrr\n") == 0)
	{
		ft_reverse_rotate(*a);
		ft_reverse_rotate(*b);
	}
	return (ft_new_cmd(command));
}

t_cmd			*ft_comnd(t_stack **a, t_stack **b, t_ps_flags *fl, char *comnd)
{
	if (fl->v)
	{
		ft_ps_status(*a, *b, 0);
		ft_printf("Command #%d : %s", fl->i++, comnd);
	}
	if (ft_strcmp(comnd, "sa\n") == 0)
		ft_swap(*a);
	else if (ft_strcmp(comnd, "sb\n") == 0)
		ft_swap(*b);
	else if (ft_strcmp(comnd, "ss\n") == 0)
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (ft_strcmp(comnd, "pa\n") == 0)
		ft_push(a, b);
	else if (ft_strcmp(comnd, "pb\n") == 0)
		ft_push(b, a);
	else if (ft_strcmp(comnd, "ra\n") == 0)
		ft_rotate(*a);
	return (ft_comnd2(a, b, comnd));
}
