/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:34:07 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/02 23:56:49 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

const char	*skip_whitespace(const char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int	ft_atoi(const char	*str)
{
	long	n;
	long	sign;

	n = 0;
	sign = 1;
	str = skip_whitespace(str);
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str != '\0') && ('0' <= *str) && (*str <= '9'))
	{
		n = (n * 10) + (*str - '0');
		if (n > 2147483647 && sign == 1)
			return (-1);
		if (n > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (n * sign);
}
