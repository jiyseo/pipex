/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:20:14 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/02 23:55:33 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!find[0])
		return ((char *)str);
	i = 0;
	while (str[i] && i + ft_strlen(find) <= len)
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (find[j] || str[i + j])
			{
				if (str[i + j] != find[j])
					break ;
				else if (j == ft_strlen(find) - 1)
					return ((char *)str + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
