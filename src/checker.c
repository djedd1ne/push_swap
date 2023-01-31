/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:45:35 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 21:59:01 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	combine_checker(int (*operation) (t_stack **s, char c), t_stack **s1,
		t_stack **s2)
{
	if ((operation(s1, NOPRINT) + operation(s2, NOPRINT)) != 0)
		return (1);
	else
		return (0);
}

void	run_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap_s(a, NOPRINT);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap_s(b, NOPRINT);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		combine_checker(swap_s, a, b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push_s(b, a, NOPRINT);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push_s(a, b, NOPRINT);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate_s(a, NOPRINT);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate_s(b, NOPRINT);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		combine_checker(rotate_s, a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rev_rotate(a, NOPRINT);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rev_rotate(b, NOPRINT);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		combine_checker(rev_rotate, a, b);
	else
		write(2, "Error\n", 6);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation != 0)
	{
		run_op(operation, a, b);
		operation = get_next_line(0);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (init_stack(ac, av, &a) != 0)
		return (1);
	size = count_index(&a);
	if (chck_sort_asc(&a, size) == 1)
		return (1);
	checker(&a, &b);
	if (chck_sort_asc(&a, size) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freelist(a);
	return (0);
}
