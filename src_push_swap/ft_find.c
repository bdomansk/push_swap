/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:19:34 by bdomansk          #+#    #+#             */
/*   Updated: 2018/07/23 16:19:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_max(t_stack *stack, int *length)
{
	t_stack *temp;
	int		i;
	int		max;

	i = 0;
	temp = stack;
	max = temp->num;
	*length = 0;
	while (temp)
	{
		if (temp->num > max)
		{
			*length = i;
			max = temp->num;
		}
		temp = temp->next;
		i++;
	}
	return (max);
}

int	ft_find_min(t_stack *stack, int *length)
{
	t_stack *temp;
	int		i;
	int		min;

	i = 1;
	temp = stack;
	min = temp->num;
	*length = 1;
	while (temp)
	{
		if (temp->num < min)
		{
			*length = i;
			min = temp->num;
		}
		temp = temp->next;
		i++;
	}
	return (min);
}

int	ft_find_last(t_stack *stack)
{
	t_stack	*s;

	s = stack;
	while (s->next)
		s = s->next;
	return (s->num);
}

int	ft_max_with_limit(t_stack *stack, int limit, int *len)
{
	t_stack *temp;
	int		i;
	int		max;

	i = 0;
	temp = stack;
	max = -2147483648;
	*len = 1;
	if (limit > ft_find_max(stack, len))
		return (ft_find_max(stack, len));
	while (temp)
	{
		if (temp->num > max && temp->num < limit)
		{
			max = temp->num;
			*len = i;
		}
		temp = temp->next;
		i++;
	}
	return (max);
}

int	ft_min_with_limit(t_stack *stack, int limit, int *len)
{
	t_stack *temp;
	int		i;
	int		min;

	i = 1;
	temp = stack;
	min = 2147483647;
	*len = 1;
	if (limit > ft_find_max(stack, len))
		return (ft_find_min(stack, len));
	while (temp)
	{
		if (temp->num < min && temp->num > limit)
		{
			min = temp->num;
			*len = i;
		}
		temp = temp->next;
		i++;
	}
	return (min);
}
