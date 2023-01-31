/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:24:52 by djmekki           #+#    #+#             */
/*   Updated: 2022/05/16 15:05:46 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_diu(long n)
{
	char	*res;
	int		count;

	count = 0;
	res = ft_ltoa(n);
	ft_putstr_fd(res, 1);
	count = ft_strlen(res);
	free(res);
	return (count);
}
