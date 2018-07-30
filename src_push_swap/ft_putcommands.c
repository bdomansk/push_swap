/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcommands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:34:42 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/24 15:34:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putcommands(t_cmd *comnd, t_ps_flags *fl)
{
	int		i;
	t_cmd	*cmd;

	cmd = comnd;
	i = 0;
	while (cmd)
	{
		if (cmd->command)
		{
			if (fl->v)
			{
				ft_printf("%d) ", i);
				if (fl->f)
					ft_printf("%s", cmd->command);
			}
			if (fl->f)
				write(fl->f, cmd->command, ft_strlen(cmd->command));
			else
				ft_printf("%s", cmd->command);
			i++;
		}
		cmd = cmd->next;
	}
}
