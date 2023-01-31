/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:50:04 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 21:58:06 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_s(a, 'a');
	else if (size == 3)
		sort_3(a);
	else
		median_sort_a(a, b, size, 0);
}

int	main(int ac, t_string *av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (init_stack(ac, av, &a) != 0)
		return (1);
	size = count_index(&a);
	if (chck_sort_asc(&a, size) == 1)
		return (1);
	sort(&a, &b, size);
	freelist(a);
	return (0);
}
