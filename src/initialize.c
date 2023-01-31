/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:54:36 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 05:53:59 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	fill_linkedlist(t_stack **a, t_string value)
{
	int			i;
	t_string	*nb_split;
	int			flag;
	long		n;
	t_stack		*tmp;

	i = 0;
	nb_split = ft_split(value, ' ');
	if (*(nb_split) == NULL)
		return (1);
	while (*(nb_split + i) != NULL)
	{
		flag = chck_atoi(*(nb_split + i), &n);
		if (flag)
			return (1);
		push(a, n);
		i++;
	}
	tmp = find_last(*a);
	free(tmp->next);
	tmp->next = NULL;
	free_split(nb_split, i);
	return (0);
}
