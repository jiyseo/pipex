/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:38:26 by jiyseo            #+#    #+#             */
/*   Updated: 2022/04/05 13:56:19 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n);
void	free_read_buffer(t_read_buffer *prb);

static char	*realloc_line_buffer(t_line_buffer	*plb)
{
	char	*new_buf;
	size_t	new_size;

	new_size = plb->size + LINE_BUF_SIZE;
	new_buf = malloc(sizeof(char) * (new_size + 1));
	if (plb->buf != NULL)
	{
		if (new_buf != NULL)
			ft_memcpy(new_buf, plb->buf, plb->size);
		free(plb->buf);
	}
	plb->buf = new_buf;
	plb->size = new_size;
	return (new_buf);
}

static char	*alloc_read_buffer(t_read_buffer *prb)
{
	if (prb->buf == NULL)
	{
		prb->buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (prb->buf == NULL)
			return (NULL);
		prb->pos = 0;
		prb->size = 0;
	}
	return (prb->buf);
}

static int	read_char(int fd, t_read_buffer *prb)
{
	if (prb->pos >= prb->size)
	{
		prb->size = read(fd, prb->buf, BUFFER_SIZE);
		if (prb->size < 1)
			return ('\0');
		prb->pos = 0;
	}
	return (prb->buf[prb->pos++]);
}

static int	put_line_char(t_line_buffer *plb, char ch)
{
	if (plb->pos >= plb->size)
	{
		if (realloc_line_buffer(plb) == NULL)
			return (0);
	}
	plb->buf[plb->pos++] = ch;
	if (ch == '\n')
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	int						ch;
	t_line_buffer			lb;
	static t_read_buffer	rb[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (alloc_read_buffer(&rb[fd]) == NULL)
		return (NULL);
	lb.buf = NULL;
	lb.pos = 0;
	lb.size = 0;
	while (1)
	{
		ch = read_char(fd, &rb[fd]);
		if (ch == '\0')
			break ;
		if (put_line_char(&lb, ch) == 0)
			break ;
	}
	if (lb.pos == 0)
		free_read_buffer(&rb[fd]);
	else
		lb.buf[lb.pos] = '\0';
	return (lb.buf);
}
