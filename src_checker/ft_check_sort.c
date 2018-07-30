/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:10:28 by bdomansk          #+#    #+#             */
/*   Updated: 2018/06/10 17:10:30 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_sort(t_stack *a, t_ps_flags *fl)
{
	t_stack *temp;
	t_stack *next;

	temp = a;
	while (temp)
	{
		next = temp->next;
		if (next && next->num < temp->num)
			ft_ps_ko(fl, "numbers unsorted");
		temp = temp->next;
	}
}
