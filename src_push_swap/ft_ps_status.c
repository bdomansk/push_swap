/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:27:43 by bdomansk          #+#    #+#             */
/*   Updated: 2018/06/10 15:27:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ps_status(t_stack *a, t_stack *b, int clr)
{
	if (clr)
	{
		write(1, YELLOW, ft_strlen(YELLOW));
		ft_printf("\n___________________________\nStack a:\n");
		ft_putstack(a);
		ft_printf("___________________________\nStack b:\n");
		ft_putstack(b);
		ft_printf("___________________________\n");
		write(1, DEF, ft_strlen(DEF));
	}
	else
	{
		ft_printf("\n___________________________\nStack a:\n");
		ft_putstack(a);
		ft_printf("___________________________\nStack b:\n");
		ft_putstack(b);
		ft_printf("___________________________\n");
	}
}

void	ft_ps_command(t_ps_flags *fl, char *line, int i)
{
	if (line)
		ft_printf("Command #%d : ", i);
	if (fl->f && line)
		ft_printf("%s\n", line);
}
