/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:53:04 by bdomansk          #+#    #+#             */
/*   Updated: 2018/05/18 14:53:06 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack *s)
{
	int		first;
	t_stack	*start;

	if (!s || !s->next)
		return ;
	start = s;
	first = s->num;
	while (s->next)
	{
		s->num = (s->next)->num;
		s = s->next;
	}
	s->num = first;
	s = start;
}
