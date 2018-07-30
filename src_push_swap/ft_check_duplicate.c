/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:09:21 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/24 15:09:23 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_duplicate(t_stack *stack_a, t_ps_flags *flags)
{
	t_stack *temp;
	t_stack *next;

	temp = stack_a;
	while (temp)
	{
		next = temp->next;
		while (next)
		{
			if (next->num == temp->num)
				ft_ps_error(flags, "some numbers are duplicates");
			next = next->next;
		}
		temp = temp->next;
	}
}
