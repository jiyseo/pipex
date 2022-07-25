/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:05:11 by jiyseo            #+#    #+#             */
/*   Updated: 2022/07/25 05:26:19 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex_child(t_pipex *px, int idx)
{
	char	**argv;
	char	*pathfile;

	if (px->heredoc_limiter)
		close(px->heredoc_fd[1]);
	pipex_dup2(px->prev_in_fd, STDIN_FILENO);
	if (idx >= px->lastchildidx)
		pipex_dup2(px->out_fd, STDOUT_FILENO);
	else
	{
		close(px->out_fd);
		close(px->pipe_fd[0]);
		pipex_dup2(px->pipe_fd[1], STDOUT_FILENO);
	}
	argv = ft_split(px->cmdv[idx], ' ');
	if (!argv)
		pipex_memory_error();
	pathfile = find_path(argv[0], px->envp);
	if (!pathfile)
		pipex_error("%s: command not found", argv[0]);
	execve(pathfile, argv, px->envp);
	free(pathfile);
	ft_free_array(argv);
	pipex_perror("execve failed");
}

static void	pipex_parent(t_pipex *px, int idx)
{
	if (idx < px->lastchildidx)
	{
		close(px->prev_in_fd);
		px->prev_in_fd = px->pipe_fd[0];
		close(px->pipe_fd[1]);
	}
}

static int	pipex_process(t_pipex *px, int idx)
{
	int	pid;

	if ((unsigned int)idx > (unsigned int)px->lastchildidx)
		return (1);
	if (idx < px->lastchildidx && pipe(px->pipe_fd) == -1)
		return (pipex_perror("pipe failed"));
	pid = fork();
	if (pid == -1)
		return (pipex_perror("fork failed"));
	if (pid > 0)
	{
		pipex_parent(px, idx);
	}
	else
	{
		pipex_child(px, idx);
		exit(0);
	}
	return (pipex_process(px, idx + 1));
}

static int	pipex_init(t_pipex *px, int argc, char *argv[], char *envp[])
{
	int	firstcmdidx;

	if (argc < 5)
		return (pipex_error("argument error"));
	firstcmdidx = 2;
	if (ft_strcmp(argv[1], "here_doc") != 0)
	{
		px->heredoc_limiter = NULL;
		px->in_fd = open(argv[1], O_RDONLY);
		if (px->in_fd < 0)
			return (pipex_perror("%s open failed", argv[1]));
	}
	else
	{
		firstcmdidx++;
		px->heredoc_limiter = argv[2];
		if (pipe(px->heredoc_fd) == -1)
			return (pipex_perror("here_doc pipe failed"));
	}
	px->lastchildidx = argc - firstcmdidx - 2;
	px->cmdv = argv + firstcmdidx;
	px->envp = envp;
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	px;
	int		flag;

	pipex_init(&px, argc, argv, envp);
	if (px.heredoc_limiter)
	{
		px.prev_in_fd = px.heredoc_fd[0];
		flag = O_APPEND;
	}
	else
	{
		px.prev_in_fd = px.in_fd;
		flag = O_TRUNC;
	}
	px.out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | flag, 0644);
	if (px.out_fd < 0)
		return (pipex_perror("%s open failed", argv[argc - 1]));
	if (pipex_process(&px, 0) > 0)
	{
		if (px.heredoc_limiter)
			pipex_heredoc(&px);
		wait(NULL);
	}
	close(px.out_fd);
	return (0);
}
