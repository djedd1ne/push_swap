/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_DESC.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:33:28 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/30 09:17:50 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_small_b(t_stack **a, t_stack **b, int size)
{
	if (size == 1)
		push_s(b, a, 'a');
	else if (size == 2)
	{
		if ((*b)->nb < (*b)->next->nb)
			swap_s(b, 'b');
		while (size--)
			push_s(b, a, 'a');
	}
	else if (size == 3)
	{
		while (size || !((*a)->nb < (*a)->next->nb
				&& (*a)->next->nb < (*a)->next->next->nb))
		{
			if (size == 1 && (*a)->nb > (*a)->next->nb)
				swap_s(a, 'a');
			else if (size == 1 || (size >= 2
					&& (*b)->nb > (*b)->next->nb)
				|| (size == 3 && (*b)->nb > (*b)->next->next->nb))
					size = push_size(a, b, size, 1);
			else
				swap_s(b, 'b');
		}
	}
	return (0);
}
