/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:35:14 by djmekki           #+#    #+#             */
/*   Updated: 2022/05/20 12:05:38 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static int	print_cases(char c, va_list ap)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printf_c(va_arg(ap, int));
	else if (c == 's')
		len = ft_printf_s(va_arg(ap, char *));
	else if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		len = ft_printf_p_x_capx(va_arg(ap, unsigned long), 0) + 2;
	}
	else if (c == 'd' || c == 'i')
		len = ft_printf_diu(va_arg(ap, int));
	else if (c == 'u')
		len = ft_printf_diu(va_arg(ap, unsigned int));
	else if (c == 'x')
		len = ft_printf_p_x_capx(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		len = ft_printf_p_x_capx(va_arg(ap, unsigned int), 1);
	else if (c == '%')
		len = ft_printf_percentage('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		res;
	va_list	ap;

	i = 0;
	res = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			res += print_cases(format[i + 1], ap);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
		}
		i++;
	}
	va_end(ap);
	return (res);
}
