/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 13:53:07 by bdomansk          #+#    #+#             */
/*   Updated: 2018/05/04 13:53:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstack(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		ft_printf("%d) %d\n", i, stack->num);
		i++;
		stack = stack->next;
	}
}
