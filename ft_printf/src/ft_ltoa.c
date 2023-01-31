/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:24:31 by djmekki           #+#    #+#             */
/*   Updated: 2022/05/16 12:48:12 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	else if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_ltoa(long n)
{
	char	*str;
	size_t	len;
	long	nb;

	len = ft_intlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		nb = n * -1;
	}
	else
		nb = n;
	if (nb == 0)
		*str = '0';
	while (nb)
	{
		str[--len] = nb % 10 + '0';
		nb /= 10;
	}
	str[ft_intlen(n)] = 0;
	return (str);
}
