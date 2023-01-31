/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:04:38 by djmekki           #+#    #+#             */
/*   Updated: 2023/02/01 00:13:17 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define NOPRINT '0'
# define ASC 0
# define DESC 1
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "../ft_printf/includes/ft_printf.h"

typedef char	*t_string;
typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

// functions.c
int		swap_s(t_stack **s, char c);
int		push_s(t_stack **src, t_stack **dst, char c);
int		rotate_s(t_stack **s, char c);
int		rev_rotate(t_stack **s, char c);
int		combine(int (*operation) (t_stack **s, char c), t_stack **s1,
			t_stack **s2, char c);

// functions_utils
t_stack	*new_node(int num);
t_stack	*find_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	free_split(t_string *split, int n);

// initialize
int		fill_linkedlist(t_stack **a, t_string value);

// index 
int		push(t_stack **stack, int value);
void	ft_swap(int *a, int *b);
t_stack	*stack_duplicate(t_stack *stack, int size);
t_stack	*sort_duplicated(t_stack *stack, int size);
void	stack_index(t_stack *stack, t_stack *sorted);

// chck_utils
int		count_index(t_stack **s);
int		chck_atoi(t_string str, long *res);
int		ft_list_size(t_stack *s);

// chck_stack
int		chck_duplicate(t_stack **a);
int		chck_sort_asc(t_stack **a, int size);
int		chck_sort_desc(t_stack **b, int size);
void	free_stack(t_stack *stack);
int		init_stack(int ac, t_string *av, t_stack **a);

// utils
int		push_size(t_stack **s1, t_stack **s2, int size, int op);
int		get_median(t_stack *s, int *median, int size);

// median_sort.c
int		median_sort_a(t_stack **a, t_stack **b, int size, int count);
int		median_sort_b(t_stack **a, t_stack **b, int size, int count);

// median_sort.c
void	sort_3(t_stack **s);
void	median_sort_3(t_stack **a, t_stack **b, int size);

// sort_small_DESC.c
int		sort_small_b(t_stack **a, t_stack **b, int size);
void	freelist(t_stack *head);

#endif