/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:44:20 by bdomansk          #+#    #+#             */
/*   Updated: 2018/05/04 11:44:23 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_check_line2(t_stack **a, t_stack **b, char *l, t_ps_flags *fl)
{
	if (ft_strcmp(l, "rr") == 0)
	{
		ft_rotate(*a);
		ft_rotate(*b);
	}
	else if (ft_strcmp(l, "rra") == 0)
		ft_reverse_rotate(*a);
	else if (ft_strcmp(l, "rrb") == 0)
		ft_reverse_rotate(*b);
	else if (ft_strcmp(l, "rrr") == 0)
	{
		ft_reverse_rotate(*a);
		ft_reverse_rotate(*b);
	}
	else
	{
		if (fl->v)
			ft_ps_status(*a, *b, fl->c);
		free(l);
		ft_free_stack(*b);
		ft_free_stack(*a);
		ft_ps_error(fl, "instruction don’t exist");
	}
}

static void	ft_check_line(t_stack **a, t_stack **b, char *l, t_ps_flags *fl)
{
	if (ft_strcmp(l, "sa") == 0)
		ft_swap(*a);
	else if (ft_strcmp(l, "sb") == 0)
		ft_swap(*b);
	else if (ft_strcmp(l, "ss") == 0)
	{
		ft_swap(*a);
		ft_swap(*b);
	}
	else if (ft_strcmp(l, "pa") == 0)
		ft_push(a, b);
	else if (ft_strcmp(l, "pb") == 0)
		ft_push(b, a);
	else if (ft_strcmp(l, "ra") == 0)
		ft_rotate(*a);
	else if (ft_strcmp(l, "rb") == 0)
		ft_rotate(*b);
	else
		ft_check_line2(a, b, l, fl);
}

static void	ft_check_stack_b(t_stack *a, t_stack *b, t_ps_flags *fl)
{
	if (fl->v)
		ft_ps_status(a, b, fl->c);
	if (b)
	{
		ft_free_stack(b);
		ft_free_stack(a);
		ft_ps_ko(fl, "stack b doesn't empty");
	}
}

void		ft_check_commands(t_stack *stack_a, t_ps_flags *flags, int fd)
{
	char	*line;
	t_stack	*stack_b;

	line = NULL;
	stack_b = NULL;
	if (flags->v)
		ft_ps_status(stack_a, stack_b, 0);
	if (flags->v && !flags->f)
		ft_ps_command(flags, "0", flags->i++);
	while (get_next_line(fd, &line) == 1)
	{
		if (flags->v && flags->f)
			ft_ps_command(flags, line, flags->i++);
		ft_check_line(&stack_a, &stack_b, line, flags);
		if (flags->v)
			ft_ps_status(stack_a, stack_b, 0);
		if (flags->v && !flags->f)
			ft_ps_command(flags, line, flags->i++);
		free(line);
		line = NULL;
	}
	ft_check_stack_b(stack_a, stack_b, flags);
}
