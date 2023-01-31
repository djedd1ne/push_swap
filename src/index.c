/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:48:37 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 18:15:33 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	tmp = NULL;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		write(2, "Error\n", 6);
		free(new_node);
		return (0);
	}
	new_node->nb = value;
	new_node->next = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
	return (1);
}

t_stack	*stack_duplicate(t_stack *stack, int size)
{
	t_stack	*new;
	t_stack	*head;
	int		i;

	i = 0;
	new = NULL;
	head = stack;
	while (i < size)
	{
		push(&new, stack->nb);
		stack = stack->next;
		i++;
	}
	stack = head;
	return (new);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

t_stack	*sort_duplicated(t_stack *stack, int size)
{
	t_stack	*duplicate;
	t_stack	*head;
	int		swapped;

	swapped = 1;
	head = stack_duplicate(stack, size);
	duplicate = head;
	while (swapped == 1)
	{
		swapped = 0;
		while (duplicate->next != NULL)
		{
			if (duplicate->nb > duplicate->next->nb)
			{
				ft_swap(&duplicate->nb, &duplicate->next->nb);
				swapped = 1;
			}
			duplicate = duplicate->next;
		}
		duplicate->next = NULL;
		duplicate = head;
	}
	return (duplicate);
}
