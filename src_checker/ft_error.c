/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:37:23 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/18 15:37:25 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_wait(void)
{
	int i;

	i = -10000;
	while (i < 2147483645)
		i++;
}

void	ft_ps_error(t_ps_flags *fl, char *reason)
{
	if (fl->e)
	{
		if (fl->c)
		{
			ft_putcolourstr("Error : ", RED);
			ft_putcolourstr(reason, RED);
			ft_printf(" \n");
		}
		else
			ft_printf("Error : %s\n", reason);
	}
	else if (fl->c)
		ft_putcolourstr("Error\n", RED);
	else
		ft_putstr_fd("Error\n", 2);
	if (fl->l)
		system("leaks checker");
	free(fl);
	exit(1);
}

void	ft_ps_ko(t_ps_flags *fl, char *reason)
{
	if (fl->e)
	{
		if (fl->c)
		{
			ft_putcolourstr("KO : ", RED);
			ft_putcolourstr(reason, RED);
			ft_printf(" \n");
		}
		else
			ft_printf("KO : %s\n", reason);
	}
	else if (fl->c)
		ft_putcolourstr("KO\n", RED);
	else
		ft_printf("KO\n");
	if (fl->l)
		system("leaks checker");
	free(fl);
	exit(0);
}
