/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:16:29 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:56:38 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# define FLAG_MINUS	0x01
# define FLAG_PLUS	0x02
# define FLAG_SPACE	0x04
# define FLAG_ZERO	0x08
# define FLAG_SHARP	0x10

typedef struct s_info {
	char		type;
	char		flag;
	int			width;
	int			precision;
	int			fd;
	int			count;
	const char	*fmt;
	char		*buf;
	int			buf_size;
	va_list		ap;
}	t_info;

int		ft_printf(const char *format, ...);
int		ft_vprintf(const char *format, va_list ap);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_snprintf(char *buf, int buf_size, const char *format, ...);
int		ft_vsnprintf(char *buf, int buf_size, const char *format, va_list ap);
int		print_format(t_info *inf, const char *format);
int		put_char(t_info *inf, char c);
size_t	ft_strlen(const char *s);
void	fill_char(t_info *inf, char ch, int count);
void	fill_left(t_info *inf);
void	fill_right(t_info *inf);
void	print_char(t_info *inf, char ch);
void	print_string(t_info *inf, char *str);
void	print_nbr(t_info *inf, unsigned long long nbr, int radix);
int		get_width(t_info *inf);
void	parse_flags(t_info *inf);
void	parse_width(t_info *inf);
void	parse_format(t_info *inf);

#endif
