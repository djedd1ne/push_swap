/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:08:48 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 18:50:20 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap_s(t_stack **s, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *s;
	*s = (*s)->next;
	tmp2 = *s;
	*s = (*s)->next;
	tmp1->next = *s;
	tmp2->next = tmp1;
	*s = tmp2;
	if (c != NOPRINT)
		ft_printf("s%c\n", c);
	return (0);
}

int	push_s(t_stack **src, t_stack **dst, char c)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	if (c != NOPRINT)
		ft_printf("p%c\n", c);
	return (0);
}

int	rotate_s(t_stack **s, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = (*s)->next;
	(*s)->next = NULL;
	if (tmp1 == NULL)
		tmp1 = *s;
	else
	{
		tmp2 = tmp1;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = *s;
		*s = tmp1;
	}
	if (c != NOPRINT)
		ft_printf("r%c\n", c);
	return (0);
}

int	rev_rotate(t_stack **s, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*s)->next == NULL)
		return (0);
	tmp1 = find_last(*s);
	tmp2 = new_node(tmp1->nb);
	tmp1 = *s;
	while (tmp1->next != NULL)
	{
		if (tmp1->next->next == NULL)
		{
			free(tmp1->next);
			tmp1->next = NULL;
		}
		else
			tmp1 = tmp1->next;
	}
	stack_add_back(&tmp2, *s);
	*s = tmp2;
	if (c != NOPRINT)
		ft_printf("rr%c\n", c);
	return (0);
}

int	combine(int (*operation) (t_stack **s, char c), t_stack **s1,
		t_stack **s2, char c)
{
	if ((operation(s1, NOPRINT) + operation(s2, NOPRINT)) == 0)
	{
		if (c == 'R')
			ft_printf("rrr\n");
		if (c == 'r')
			ft_printf("rr\n");
		if (c == 's')
			ft_printf("ss\n");
		return (0);
	}
	return (1);
}
