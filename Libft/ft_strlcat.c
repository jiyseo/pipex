/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:49:55 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 00:02:22 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	n;
	char			*p;

	p = dst;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	n = dstsize - dst_len - 1;
	while (*p)
		p++;
	while (*src != '\0' && n)
	{
		*p++ = *src++;
		n--;
	}
	*p = '\0';
	return (dst_len + src_len);
}
