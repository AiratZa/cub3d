/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:10:07 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/09 21:13:36 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_fd
{
	int			fd;
	char		*left;
	char		*left_begin;
	struct s_fd	*next;
}					t_fd;

int					get_next_line(int fd, char **line);

t_fd				*new_fd_to_read(int fd);

/*
**FUNCTIONS FROM FTLIB. STRJOIN REBUILD
*/

char				*ft_strjoin_re(char **s1, char *s2);

#endif
