/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:46:21 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 05:51:41 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack **s)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp1 = (*s)->nb;
	tmp2 = (*s)->next->nb;
	tmp3 = (*s)->next->next->nb;
	if (tmp1 > tmp2 && tmp1 > tmp3 && tmp2 < tmp3)
		rotate_s(s, 'a');
	else if (tmp1 > tmp2 && tmp1 < tmp3 && tmp2 < tmp3)
		swap_s(s, 'a');
	else if (tmp1 > tmp2 && tmp1 > tmp3 && tmp2 > tmp3)
	{
		rotate_s(s, 'a');
		swap_s(s, 'a');
	}
	else if (tmp1 < tmp2 && tmp1 < tmp3 && tmp2 > tmp3)
	{
		rev_rotate(s, 'a');
		swap_s(s, 'a');
	}
	else if (tmp1 < tmp2 && tmp1 > tmp3 && tmp2 > tmp3)
		rev_rotate(s, 'a');
	else
		return ;
}

void	median_sort_3(t_stack **a, t_stack **b, int size)
{
	if (size == 3 && count_index(a) == 3)
		sort_3(a);
	else if (size == 2)
	{
		if ((*a)->nb > (*a)->next->nb)
			swap_s(a, 'a');
	}
	else if (size == 3)
	{
		while (size != 3 || !((*a)->nb < (*a)->next->nb
				&& (*a)->next->nb < (*a)->next->next->nb))
		{
			if (size == 3 && (*a)->nb > (*a)->next->nb
				&& (*a)->next->next != NULL)
				swap_s(a, 'a');
			else if (size == 3 && !((*a)->next->next->nb > (*a)->nb
					&& (*a)->next->next->nb > (*a)->next->nb))
					size = push_size(a, b, size, 0);
			else if ((*a)->nb > (*a)->next->nb)
				swap_s(a, 'a');
			else if (size++)
				push_s(b, a, 'a');
		}
	}
}
