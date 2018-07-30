/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:45:25 by bdomansk          #+#    #+#             */
/*   Updated: 2018/05/07 13:45:28 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack *stack)
{
	int temp;

	if (stack && stack->next)
	{
		temp = (stack->next)->num;
		(stack->next)->num = stack->num;
		stack->num = temp;
	}
}
