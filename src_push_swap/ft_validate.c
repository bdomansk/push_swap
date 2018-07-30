/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:22:00 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/16 16:22:02 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_only_digits(int len, char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < len)
	{
		temp = ft_whitespaces(arr[i]);
		j = 0;
		if (temp[j] && (temp[j] == '-' || temp[j] == '+'))
			j++;
		while (temp[j] && temp[j] >= 48 && temp[j] <= 57)
			j++;
		if (temp[j])
			return (1);
		i++;
	}
	return (0);
}

static	int		ft_int_limit(int len, char **arr)
{
	int				i;
	int				j;
	unsigned int	x;
	char			*temp;
	int				sign;

	i = -1;
	while (++i < len)
	{
		temp = ft_whitespaces(arr[i]);
		j = 0;
		sign = (temp[j] && temp[j] == '-') ? -1 : 1;
		j = (temp[j] && (temp[j] == '-' || temp[j] == '+')) ? 1 : 0;
		x = 0;
		while (temp[j])
		{
			x = x * 10 + temp[j++] - '0';
			if (x > 2147483647 && sign == 1)
				return (1);
			if (x > 2147483648 && sign == -1)
				return (1);
		}
	}
	return (0);
}

static int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i] && ft_strlen(arr[i]))
		i++;
	return (i);
}

static	t_stack	*ft_get_stack(int len, char **arr)
{
	t_stack *stack;

	stack = NULL;
	if (len)
	{
		stack = (t_stack*)malloc(sizeof(t_stack));
		stack->num = ft_atoi(arr[0]);
		stack->next = ft_get_stack(len - 1, ++arr);
	}
	return (stack);
}

t_stack			*ft_validate(int *len, char **arr, t_ps_flags *flags)
{
	int		err;
	t_stack	*stack_a;
	char	**splited;

	if (*len > 1)
	{
		err = ft_only_digits(*len, arr);
		err += ft_int_limit(*len, arr);
		if (err)
			ft_ps_error(flags, "arguments aren't numbers or > the int limit");
		stack_a = ft_get_stack(*len, arr);
	}
	else
	{
		splited = ft_strsplit(arr[0], ' ');
		(*len) = ft_arrlen(splited);
		err = ft_only_digits(*len, splited);
		err += ft_int_limit(*len, splited);
		if (err && ft_free_arr(*len, splited))
			ft_ps_error(flags, "arguments aren't numbers or > the int limit");
		stack_a = ft_get_stack(*len, splited);
		ft_free_arr(*len, splited);
	}
	return (stack_a);
}
