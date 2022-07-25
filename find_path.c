/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:06:09 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:22:53 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(char *path, char *file)
{
	char	*mem;
	char	*p;

	mem = (char *)malloc(sizeof(char) * (ft_strlen(path)
				+ ft_strlen(file) + 2));
	if (!mem)
		return (pipex_memory_error());
	p = mem;
	while (*path)
		*p++ = *path++;
	if (p > mem && p[-1] != '/')
		*p++ = '/';
	while (*file)
		*p++ = *file++;
	*p = '\0';
	return (mem);
}

static char	*find_file(char *pathlist, char *file)
{
	int		i;
	char	**patharr;
	char	*pathfile;

	patharr = ft_split(pathlist, ':');
	if (!patharr)
		return (pipex_memory_error());
	i = 0;
	while (patharr[i])
	{
		pathfile = join_path(patharr[i], file);
		if (!pathfile || access(pathfile, X_OK) == 0)
			break ;
		free(pathfile);
		i++;
	}
	if (!patharr[i])
		pathfile = NULL;
	ft_free_array(patharr);
	return (pathfile);
}

char	*find_path(char *cmd, char *envp[])
{
	int	i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) != 0)
			return (NULL);
		cmd = ft_strdup(cmd);
		if (!cmd)
			return (pipex_memory_error());
		return (cmd);
	}
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (find_file(envp[i] + 5, cmd));
		i++;
	}
	return (NULL);
}
