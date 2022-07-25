/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:35:03 by jiyseo            #+#    #+#             */
/*   Updated: 2022/04/05 13:35:05 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char	*in_dst;
	unsigned char	*in_src;

	if (!dst && !src)
		return (NULL);
	in_dst = (unsigned char *) dst;
	in_src = (unsigned char *) src;
	while (n-- > 0)
		*in_dst++ = *in_src++;
	return (dst);
}

void	free_read_buffer(t_read_buffer *prb)
{
	if (prb->buf != NULL)
	{
		free(prb->buf);
		prb->buf = NULL;
	}
}
