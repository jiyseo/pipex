/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:09:55 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:36:25 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_format(t_info *inf, const char *format)
{
	inf->count = 0;
	inf->fmt = format;
	while (*inf->fmt)
	{
		if (*inf->fmt == '%')
			parse_format(inf);
		else
			put_char(inf, *inf->fmt++);
	}
	return (inf->count);
}

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_info	inf;

	if (!format || fd < 0)
		return (0);
	inf.fd = fd;
	inf.buf_size = 0;
	va_copy(inf.ap, ap);
	return (print_format(&inf, format));
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(fd, format, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_vdprintf(STDOUT_FILENO, format, ap));
}
