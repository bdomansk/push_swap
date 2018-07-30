/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:27:44 by bdomansk          #+#    #+#             */
/*   Updated: 2018/04/16 16:27:45 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_stack
{
	int				num;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_cmd
{
	char			*command;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_rotates
{
	int	ra;
	int	rb;
	int	rra;
	int rrb;
	int	rr;
	int	rrr;
	int	min;
	int	type;
}				t_rotates;

typedef struct	s_ps_flags
{
	int	v;
	int	c;
	int	f;
	int	h;
	int	e;
	int	l;
	int	i;
}				t_ps_flags;

t_ps_flags		*ft_check_ps_flags(char **argv, int *len);
t_stack			*ft_validate(int *len, char **arr, t_ps_flags *flags);
void			ft_check_duplicate(t_stack *stack_a, t_ps_flags *flags);
void			ft_check_commands(t_stack *a, t_ps_flags *fl, int fd);
void			ft_check_sort(t_stack *a, t_ps_flags *fl);

void			ft_push(t_stack **s1, t_stack **s2);
void			ft_swap(t_stack *stack);
void			ft_rotate(t_stack *s);
void			ft_reverse_rotate(t_stack *s);

void			ft_free_stack(t_stack *stack);
int				ft_free_arr(int len, char **splited);
void			ft_free_stack2(t_stack *s);

int				ft_lstlen(t_stack *stack);

void			ft_wait(void);
void			ft_ps_error(t_ps_flags *fl, char *reason);
void			ft_putstack(t_stack *stack);
void			ft_putcommands(t_cmd *comnd, t_ps_flags *fl);
void			ft_ps_status(t_stack *a, t_stack *b, int clr);
void			ft_ps_ko(t_ps_flags *fl, char *reason);
void			ft_ps_command(t_ps_flags *fl, char *line, int i);

int				ft_is_sort(t_stack *stack, int asc);
int				ft_is_partly_sort(t_stack *stack, int asc);
int				ft_find_min(t_stack *stack, int *length);
int				ft_find_max(t_stack *stack, int *length);
int				ft_min_with_limit(t_stack *stack, int limit, int *len);
int				ft_max_with_limit(t_stack *stack, int limit, int *len);
int				ft_find_last(t_stack *stack);

t_cmd			*ft_comnd(t_stack **a, t_stack **b, t_ps_flags *fl, char *cmd);
t_cmd			*ft_gototheend(t_cmd *cmd);

t_cmd			*ft_sort(t_stack **a, t_stack **b, t_ps_flags *fl);
t_cmd			*ft_sort2(t_stack *a, t_stack *b, int asc, t_ps_flags *fl);
t_cmd			*ft_sort3(t_stack *a, t_stack *b, int asc, t_ps_flags *fl);
t_cmd			*ft_mini_sort(t_stack **a, t_stack **b, t_ps_flags *fl);
t_cmd			*ft_sort_stacks(t_stack **a, t_stack **b, t_ps_flags *fl);
t_cmd			*ft_push_stack_a(t_stack **a, t_stack **b, t_ps_flags *fl);
t_cmd			*ft_rotate_stack_a(t_stack **a, t_stack **b, t_ps_flags *fl);
t_cmd			*ft_prepare_pa(t_stack **a, t_stack **b, t_ps_flags *fl);
t_rotates		*ft_min_rotates(t_stack *a, t_stack *b);

#endif
