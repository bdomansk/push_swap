/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:39:55 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/23 15:39:59 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_free_arr(int len, char **splited)
{
	int i;

	i = 0;
	while (i < len)
	{
		free(splited[i]);
		i++;
	}
	free(splited);
	return (1);
}
