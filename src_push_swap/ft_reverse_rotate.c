/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 12:32:36 by bdomansk          #+#    #+#             */
/*   Updated: 2018/06/08 12:32:39 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_reverse_rotate(t_stack *s)
{
	int		temp1;
	int		temp2;
	t_stack	*start;

	if (!s || !s->next)
		return ;
	start = s;
	temp1 = s->num;
	while (s->next)
	{
		s = s->next;
		temp2 = s->num;
		s->num = temp1;
		temp1 = temp2;
	}
	s = start;
	s->num = temp1;
}
