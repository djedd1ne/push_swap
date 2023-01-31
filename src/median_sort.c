/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:44:03 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 12:31:01 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	median_sort_a(t_stack **a, t_stack **b, int size, int count)
{
	int	median;
	int	elements;

	if (chck_sort_asc(a, size) == 1)
		return (1);
	elements = size;
	if (size <= 3)
	{
		median_sort_3(a, b, size);
		return (1);
	}
	if (!count && !get_median(*a, &median, size))
		return (0);
	while (size != elements / 2 + elements % 2)
	{
		if ((*a)->nb < median && (size--))
			push_s(a, b, 'b');
		else if (++count)
			rotate_s(a, 'a');
	}
	while (elements / 2 + elements % 2 != ft_list_size(*a) && count--)
		rev_rotate(a, 'a');
	return (median_sort_a(a, b, elements / 2 + elements % 2, 0)
		&& median_sort_b(a, b, elements / 2, 0));
	return (1);
}

int	median_sort_b(t_stack **a, t_stack **b, int size, int count)
{
	int	median;
	int	elements;

	if (!count && chck_sort_desc(b, size) == 1)
		while (size--)
			push_s(b, a, 'a');
	if (size <= 3)
	{
		sort_small_b(a, b, size);
		return (1);
	}
	elements = size;
	if (!get_median(*b, &median, size))
		return (0);
	while (size != elements / 2)
	{
		if ((*b)->nb >= median && size--)
			push_s(b, a, 'a');
		else if (++count)
			rotate_s(b, 'b');
	}
	while (elements / 2 != count_index(b) && count--)
		rev_rotate(b, 'b');
	return (median_sort_a(a, b, elements / 2 + elements % 2, 0)
		&& median_sort_b(a, b, elements / 2, 0));
}
