/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:41:27 by bdomansk          #+#    #+#             */
/*   Updated: 2018/02/08 18:51:04 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_cmd		*commands;
	t_ps_flags	*flags;
	int			len;

	if (argc <= 1)
		return (0);
	stack_b = NULL;
	len = argc - 1;
	flags = ft_check_ps_flags(++argv, &len);
	argv = (len != argc - 1) ? ++argv : argv;
	stack_a = ft_validate(&len, argv, flags);
	ft_check_duplicate(stack_a, flags);
	flags->f = (flags->f) ? open("commands", O_CREAT | O_TRUNC | O_WRONLY) : 0;
	commands = ft_sort(&stack_a, &stack_b, flags);
	if (flags->v)
		ft_ps_status(stack_a, stack_b, flags->c);
	ft_putcommands(commands, flags);
	if (flags->l)
		system("leaks push_swap");
	return (0);
}
