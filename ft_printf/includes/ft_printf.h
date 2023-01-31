/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djmekki < djmekki@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:57:25 by djmekki           #+#    #+#             */
/*   Updated: 2022/05/16 12:46:16 by djmekki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_ltoa(long n);
int		ft_printf_c(int c);
int		ft_printf_s(char *s);
int		ft_printf_diu(long n);
int		ft_printf_p_x_capx(unsigned long x, int upper);
int		ft_printf_percentage(int c);
#endif