/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 02:34:25 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/03 00:01:58 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	**ft_free_array(char **arr)
{
	int	i;

	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	ft_word_count(const char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str++ == c)
			continue ;
		++cnt;
		while (*str && *str != c)
			++str;
	}
	return (cnt);
}

static void	split_strcpy(char *dst, char *from, const char *until)
{
	while (from < until)
		*(dst++) = *(from++);
	*dst = '\0';
}

static char	**split_alloc(const char *str, char c)
{
	if (!str)
		return (NULL);
	return ((char **)malloc(sizeof(char *) * (ft_word_count(str, c) + 1)));
}

char	**ft_split(const char *str, char c)
{
	char			**res;
	unsigned int	i;
	char			*from;

	res = split_alloc(str, c);
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str++ == c)
			continue ;
		from = (char *)str - 1;
		while (*str && *str != c)
			str++;
		res[i] = (char *)malloc(sizeof(char) * (str - from + 1));
		if (!(res[i]))
			return (ft_free_array(res));
		split_strcpy(res[i++], from, str);
	}
	res[i] = NULL;
	return (res);
}
