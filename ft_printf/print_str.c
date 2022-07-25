/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:16:43 by jiyseo            #+#    #+#             */
/*   Updated: 2022/05/19 16:34:27 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_info *inf, char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (inf->precision >= 0 && len > inf->precision)
		len = inf->precision;
	if (inf->width < len)
		inf->width = 0;
	else
		inf->width -= len;
	fill_left(inf);
	while (len-- > 0)
		put_char(inf, *str++);
	fill_right(inf);
}
