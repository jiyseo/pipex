/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:17:57 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/02 23:55:23 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
