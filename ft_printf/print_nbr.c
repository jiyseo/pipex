/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:18:26 by jiyseo            #+#    #+#             */
/*   Updated: 2022/05/21 03:06:54 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	print_nbr_sign(t_info *inf, unsigned long long *nbr, int radix)
{
	char	sign_ch;

	sign_ch = '\0';
	if (radix != 10)
		return (sign_ch);
	inf->flag &= ~FLAG_SHARP;
	if (inf->type == 'u')
		return (sign_ch);
	if ((int)*nbr < 0)
	{
		sign_ch = '-';
		*nbr = -*nbr;
	}
	else if (inf->flag & FLAG_PLUS)
		sign_ch = '+';
	else if (inf->flag & FLAG_SPACE)
		sign_ch = ' ';
	if (sign_ch)
		inf->width--;
	return (sign_ch);
}

static void	print_nbr_prefix(t_info *inf, char sign_ch)
{
	if (sign_ch)
		put_char(inf, sign_ch);
	if (inf->flag & FLAG_SHARP)
	{
		put_char(inf, '0');
		if (inf->type == 'X')
			put_char(inf, 'X');
		else
			put_char(inf, 'x');
	}
}

static unsigned long long	get_divisor(t_info *inf, \
								unsigned long long nbr, int radix)
{
	int					len;
	unsigned long long	divisor;

	divisor = 1;
	len = 1;
	nbr /= radix;
	while (nbr > 0)
	{
		divisor *= radix;
		len++;
		nbr /= radix;
	}
	inf->width -= len;
	if (inf->precision > 0)
	{
		inf->flag &= ~FLAG_ZERO;
		inf->precision -= len;
		if (inf->precision > 0)
			inf->width -= inf->precision;
	}
	return (divisor);
}

static void	put_nbr(t_info *inf, unsigned long long nbr, \
							unsigned long long divisor, int radix)
{
	char	digit;
	char	base_ch;

	if (inf->type == 'X')
		base_ch = 'A' - 10;
	else
		base_ch = 'a' - 10;
	while (divisor > 0)
	{
		digit = nbr / divisor;
		nbr %= divisor;
		divisor /= radix;
		if (digit < 10)
			put_char(inf, digit + '0');
		else
			put_char(inf, digit + base_ch);
	}
}

void	print_nbr(t_info *inf, unsigned long long nbr, int radix)
{
	char				sign_ch;
	unsigned long long	divisor;

	sign_ch = print_nbr_sign(inf, &nbr, radix);
	if (inf->type == 'p')
		inf->flag |= FLAG_SHARP;
	else if (nbr == 0)
		inf->flag &= ~FLAG_SHARP;
	if (inf->flag & FLAG_SHARP)
		inf->width -= 2;
	divisor = get_divisor(inf, nbr, radix);
	if (!(inf->flag & FLAG_ZERO))
		fill_left(inf);
	print_nbr_prefix(inf, sign_ch);
	if (inf->flag & FLAG_ZERO)
		fill_left(inf);
	if (inf->precision > 0)
		fill_char(inf, '0', inf->precision);
	put_nbr(inf, nbr, divisor, radix);
	fill_right(inf);
}
