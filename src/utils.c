/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:38:52 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 12:32:37 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push_size(t_stack **s1, t_stack **s2, int size, int op)
{
	if (op == 0)
		push_s(s1, s2, 'b');
	else
		push_s(s2, s1, 'a');
	size--;
	return (size);
}

int	get_median(t_stack *s, int *median, int size)
{
	t_stack	*tmp;
	t_stack	*head;
	int		index;

	index = 0;
	if (s == NULL)
		return (0);
	tmp = sort_duplicated(s, size);
	head = tmp;
	while (index < size / 2)
	{
		tmp = tmp->next;
		index++;
	}
	*median = tmp->nb;
	tmp = head;
	freelist(tmp);
	return (1);
}
