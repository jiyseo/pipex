/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:05:49 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 00:02:14 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)b;
	i = 0;
	while (i < len)
		res[i++] = (unsigned char)c;
	return (b);
}
