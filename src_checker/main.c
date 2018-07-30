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

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_ps_flags	*flags;
	int			len;
	int			fd;

	if (argc <= 1)
		return (0);
	len = argc - 1;
	flags = ft_check_ps_flags(++argv, &len);
	argv = (len != argc - 1) ? ++argv : argv;
	stack_a = ft_validate(&len, argv, flags);
	ft_check_duplicate(stack_a, flags);
	fd = (flags->f) ? open("commands", O_RDONLY) : 0;
	if (flags->f)
		ft_wait();
	ft_check_commands(stack_a, flags, fd);
	ft_check_sort(stack_a, flags);
	if (flags->c)
		ft_putcolourstr("OK\n", GREEN);
	else
		ft_printf("OK\n");
	if (flags->l)
		system("leaks checker");
	return (0);
}
