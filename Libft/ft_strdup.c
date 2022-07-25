/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:29:02 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/02 23:54:58 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*p;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	p = res;
	while (*s)
		*p++ = *s++;
	*p = '\0';
	return (res);
}

/*
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (0);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
*/
