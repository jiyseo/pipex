/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:52 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 00:01:30 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*in_dst;
	unsigned char	*in_src;

	if (!dst && !src)
		return (0);
	in_dst = (unsigned char *) dst;
	in_src = (unsigned char *) src;
	i = 0;
	while (i++ < n)
		*in_dst++ = *in_src++;
	return (dst);
}
