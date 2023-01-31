/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 03:00:24 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 20:17:15 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	chck_duplicate(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *a;
	tmp2 = tmp1->next;
	while (tmp1->next != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp1->nb == tmp2->nb)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
	return (0);
}

int	chck_sort_asc(t_stack **a, int size)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	index = 1;
	tmp1 = *a;
	tmp2 = tmp1->next;
	while (index < size)
	{
		if (tmp1->nb > tmp2->nb)
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		index++;
	}
	return (1);
}

int	chck_sort_desc(t_stack **b, int size)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		index;

	index = 1;
	tmp1 = *b;
	tmp2 = tmp1->next;
	while (index < size)
	{
		if (tmp1->nb < tmp2->nb)
			return (0);
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		index++;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	tmp2 = NULL;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	stack = NULL;
}

int	init_stack(int ac, t_string *av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (fill_linkedlist(a, *(av + i)))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (ac < 2)
		return (1);
	if (count_index(a) < 2)
		return (1);
	if (chck_duplicate(a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
