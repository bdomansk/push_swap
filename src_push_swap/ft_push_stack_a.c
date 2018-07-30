/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:05:16 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/21 18:05:17 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cmd		*ft_r1(t_stack **a, t_stack **b, t_ps_flags *fl, t_rotates *r)
{
	t_cmd		*cmd;
	t_cmd		*begin;
	t_rotates	*rotates;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	rotates = r;
	while (rotates->ra > 0)
	{
		cmd->next = ft_comnd(a, b, fl, "ra\n");
		cmd = cmd->next;
		rotates->ra--;
	}
	while (rotates->rrb > 0)
	{
		cmd->next = ft_comnd(a, b, fl, "rrb\n");
		cmd = cmd->next;
		rotates->rrb--;
	}
	return (begin);
}

t_cmd		*ft_r2(t_stack **a, t_stack **b, t_ps_flags *fl, t_rotates *r)
{
	t_cmd		*cmd;
	t_cmd		*begin;
	t_rotates	*rotates;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	rotates = r;
	while (rotates->rra > 0)
	{
		cmd->next = ft_comnd(a, b, fl, "rra\n");
		cmd = cmd->next;
		rotates->rra--;
	}
	while (rotates->rb > 0)
	{
		cmd->next = ft_comnd(a, b, fl, "rb\n");
		cmd = cmd->next;
		rotates->rb--;
	}
	return (begin);
}

t_cmd		*ft_r3(t_stack **a, t_stack **b, t_ps_flags *fl, t_rotates *r)
{
	t_cmd		*cmd;
	t_cmd		*begin;
	t_rotates	*rotates;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	rotates = r;
	while (rotates->ra > 0 || rotates->rb > 0)
	{
		if (rotates->ra > 0 && rotates->rb > 0)
		{
			cmd->next = ft_comnd(a, b, fl, "rr\n");
			rotates->ra--;
			rotates->rb--;
		}
		else if (rotates->ra-- > 0)
			cmd->next = ft_comnd(a, b, fl, "ra\n");
		else if (rotates->rb-- > 0)
			cmd->next = ft_comnd(a, b, fl, "rb\n");
		cmd = cmd->next;
	}
	return (begin);
}

t_cmd		*ft_r4(t_stack **a, t_stack **b, t_ps_flags *fl, t_rotates *r)
{
	t_cmd		*cmd;
	t_cmd		*begin;
	t_rotates	*rotates;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	rotates = r;
	while (rotates->rra > 0 || rotates->rrb > 0)
	{
		if (rotates->rra > 0 && rotates->rrb > 0)
		{
			cmd->next = ft_comnd(a, b, fl, "rrr\n");
			rotates->rra--;
			rotates->rrb--;
		}
		else if (rotates->rra-- > 0)
			cmd->next = ft_comnd(a, b, fl, "rra\n");
		else if (rotates->rrb-- > 0)
			cmd->next = ft_comnd(a, b, fl, "rrb\n");
		cmd = cmd->next;
	}
	return (begin);
}

t_cmd		*ft_push_stack_a(t_stack **a, t_stack **b, t_ps_flags *fl)
{
	t_cmd		*cmd;
	t_cmd		*begin;
	t_rotates	*rotates;

	cmd = (t_cmd*)malloc(sizeof(t_cmd));
	cmd->command = NULL;
	cmd->next = NULL;
	begin = cmd;
	if (ft_lstlen(*b) > 1)
	{
		rotates = ft_min_rotates(*a, *b);
		if (rotates->type == 1)
			cmd->next = ft_r1(a, b, fl, rotates);
		else if (rotates->type == 2)
			cmd->next = ft_r2(a, b, fl, rotates);
		else if (rotates->type == 3)
			cmd->next = ft_r3(a, b, fl, rotates);
		else
			cmd->next = ft_r4(a, b, fl, rotates);
		free(rotates);
		cmd = ft_gototheend(cmd);
	}
	cmd->next = ft_comnd(a, b, fl, "pb\n");
	return (begin);
}
