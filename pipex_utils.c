/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:05:45 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 05:57:39 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdarg.h>
#include <errno.h>

int	pipex_error(char *format, ...)
{
	va_list	ap;
	int		len;
	char	buf[128];

	va_start(ap, format);
	len = ft_snprintf(buf, 128, "pipex: ");
	len += ft_vsnprintf(buf + len, 128 - len, format, ap);
	buf[len++] = '\n';
	buf[len] = '\0';
	write(STDERR_FILENO, buf, len);
	exit(1);
	return (-1);
}

int	pipex_perror(char *format, ...)
{
	va_list	ap;
	int		len;
	char	buf[128];

	va_start(ap, format); 
	len = ft_snprintf(buf, 128, "pipex: ");
	len += ft_vsnprintf(buf + len, 128 - len, format, ap);
	len += ft_snprintf(buf + len, 128 - len, ": %s\n", strerror(errno));
	write(STDERR_FILENO, buf, len);
	exit(1);
	return (-1);
}

void	*pipex_memory_error(void)
{
	pipex_perror("memory error");
	return (NULL);
}

int	pipex_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) != -1)
		return (0);
	return (pipex_perror("dup2(%d,%d) failed", fd1, fd2));
}

int	pipex_heredoc(t_pipex *px)
{
	char	*line;
	size_t	len;

	len = ft_strlen(px->heredoc_limiter);
	while (1)
	{
		ft_printf("pipex here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (pipex_perror("get_next_line error"));
		if (ft_strlen(line) - 1 == len
			&& !ft_strncmp(line, px->heredoc_limiter, len))
			break ;
		ft_putstr_fd(line, px->heredoc_fd[1]);
		free(line);
	}
	close(px->heredoc_fd[1]);
	return (1);
}
