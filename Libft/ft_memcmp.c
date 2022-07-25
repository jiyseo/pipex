/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:56:35 by jiyseo            #+#    #+#             */
/*   Updated: 2022/01/18 17:27:14 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp_s1;
	unsigned char	*cp_s2;

	cp_s1 = (unsigned char *)s1;
	cp_s2 = (unsigned char *)s2;
	while (n)
	{
		if (*cp_s1 != *cp_s2)
			return (*cp_s1 - *cp_s2);
		cp_s1++;
		cp_s2++;
		n--;
	}
	return (0);
}
