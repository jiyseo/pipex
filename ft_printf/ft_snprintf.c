/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:09:55 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:35:44 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_vsnprintf(char *buf, int buf_size, const char *format, va_list ap)
{
	t_info	inf;

	if (!format || !buf || buf_size <= 0)
		return (0);
	inf.buf_size = buf_size;
	inf.buf = buf;
	va_copy(inf.ap, ap);
	print_format(&inf, format);
	if (inf.count >= inf.buf_size)
		inf.count--;
	buf[inf.count] = '\0';
	return (inf.count);
}

int	ft_snprintf(char *buf, int buf_size, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vsnprintf(buf, buf_size, format, ap));
}
