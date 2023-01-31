/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:14:15 by djmekki           #+#    #+#             */
/*   Updated: 2023/01/31 12:28:19 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_index(t_stack **s)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *s;
	if (tmp == NULL)
		return (i);
	else
	{
		i = 1;
		while (tmp->next != NULL)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

int	ft_list_size(t_stack *s)
{
	if (s == 0)
		return (0);
	else
		return (1 + ft_list_size(s->next));
}

int	chck_int(const t_string str, int *sign, long *res)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		*res = *res * 10 + (str[i++] - '0');
		if (*res > INT_MAX && *sign == 1)
			return (0);
		if (*res > 2147483648 && *sign == -1)
			return (0);
	}
	if (str[i] != 0)
		return (0);
	return (1);
}

int	chck_atoi(t_string str, long *res)
{
	int	sign;
	int	i;
	int	chck;

	i = 0;
	*res = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || sign == '+')
		str++;
	if (!(ft_isdigit(str[i])))
		return (-1);
	chck = chck_int(str, &sign, res);
	if (!chck)
		return (-1);
	*res *= sign;
	return (0);
}

void	freelist(t_stack *head)
{
	t_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
