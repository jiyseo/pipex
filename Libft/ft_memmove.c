/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:15:12 by jiyseo            #+#    #+#             */
/*   Updated: 2022/01/18 16:52:18 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == src || !len)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	else if (dst > src)
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
	}
	return (dst);
}
