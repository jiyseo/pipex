/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 15:56:27 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 00:03:05 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	get_divisor(int n, int *size)
{
	int				divisor;
	unsigned int	nbr;

	*size = 1;
	if (n < 0)
	{
		++*size;
		nbr = -n;
	}
	else
		nbr = n;
	divisor = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		divisor *= 10;
		++*size;
	}
	return (divisor);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				divisor;
	int				size;
	char			*res;

	divisor = get_divisor(n, &size);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	size = 0;
	nbr = n;
	if (n < 0)
	{
		res[size++] = '-';
		nbr = -n;
	}
	while (divisor > 0)
	{
		res[size++] = nbr / divisor + '0';
		nbr %= divisor;
		divisor /= 10;
	}
	res[size] = '\0';
	return (res);
}
