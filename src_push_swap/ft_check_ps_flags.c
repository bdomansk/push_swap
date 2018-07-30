/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ps_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:40:26 by bdomansk          #+#    #+#             */
/*   Updated: 2018/06/08 14:40:33 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void			ft_ps_help(t_ps_flags *fl)
{
	char	*str;

	str = "\tThe options are as follows:\n\t-h\tsee the usage\n\t-c \tuse \
colours\n\t-v\tdisplay the stack’s status\n\t-f\treading and writing from a \
file\n\t-e\terror management\n\t-l\tshow leaks\n";
	if (fl->c)
		ft_putcolourstr(str, AQUAMARINE);
	else
		ft_printf("%s", str);
	exit(1);
}

static t_ps_flags	*ft_defailt_ps_flags(void)
{
	t_ps_flags	*fl;

	fl = (t_ps_flags*)malloc(sizeof(t_ps_flags));
	fl->v = 0;
	fl->c = 0;
	fl->f = 0;
	fl->h = 0;
	fl->e = 0;
	fl->l = 0;
	fl->i = 1;
	return (fl);
}

static int			ft_find_ps_flags(t_ps_flags *fl, char *s)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (s[i])
	{
		if (s[i] != 'v' && s[i] != 'c' && s[i] != 'f' && s[i] != 'h' &&
			s[i] != 'e' && s[i] != 'l')
			return (0);
		else
			res++;
		fl->v = (s[i] == 'v') ? 1 : fl->v;
		fl->c = (s[i] == 'c') ? 1 : fl->c;
		fl->f = (s[i] == 'f') ? 1 : fl->f;
		fl->h = (s[i] == 'h') ? 1 : fl->h;
		fl->e = (s[i] == 'e') ? 1 : fl->e;
		fl->l = (s[i] == 'l') ? 1 : fl->l;
		i++;
	}
	return (res);
}

t_ps_flags			*ft_check_ps_flags(char **argv, int *len)
{
	t_ps_flags	*flags;
	int			counter;
	char		*str;

	str = argv[0];
	counter = 0;
	flags = ft_defailt_ps_flags();
	if (str[0] == '-')
		counter = ft_find_ps_flags(flags, str);
	if (counter)
		(*len)--;
	if (flags->h)
		ft_ps_help(flags);
	if (*len == 0)
	{
		flags->e = 1;
		ft_ps_error(flags, "Only flags, use the flag -h to see the usage");
	}
	return (flags);
}
