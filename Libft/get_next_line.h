/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyseo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:34:49 by jiyseo            #+#    #+#             */
/*   Updated: 2022/04/05 14:17:07 by jiyseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef LINE_BUF_SIZE
#  define LINE_BUF_SIZE 128
# endif

typedef struct s_buffer
{
	char	*buf;
	size_t	pos;
	size_t	size;
}	t_buffer;

typedef t_buffer	t_line_buffer;
typedef t_buffer	t_read_buffer;

char	*get_next_line(int fd);

#endif
