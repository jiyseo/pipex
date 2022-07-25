/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:05:36 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 00:09:24 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
//#include <sys/types.h>
# include <sys/wait.h>
# include"libft.h"
# include"ft_printf.h"

typedef struct s_pipex
{
	int		lastchildidx;
	char	**cmdv;
	char	**envp;
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	int		prev_in_fd;
	char	*heredoc_limiter;
	int		heredoc_fd[2];
}	t_pipex;

int		pipex_error(char *format, ...);
int		pipex_perror(char *format, ...);
int		pipex_dup2(int fd1, int fd2);
int		pipex_heredoc(t_pipex *px);
void	*pipex_memory_error(void);
char	*find_path(char *cmd, char *envp[]);

#endif
