/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pxcapx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:25:15 by djmekki           #+#    #+#             */
/*   Updated: 2022/05/16 21:00:11 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_p_x_capx(unsigned long x, int upper)
{
	static int	count;

	count = 0;
	if (x / 16 > 0)
		ft_printf_p_x_capx((x / 16), upper);
	x = x % 16;
	count++;
	if (x <= 9)
	{
		x += 48;
		ft_putchar_fd(x, 1);
	}
	else
	{
		x += 87;
		if (upper == 1)
			x = ft_toupper(x);
		ft_putchar_fd(x, 1);
	}
	return (count);
}
