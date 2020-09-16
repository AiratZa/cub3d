/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:09:55 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/09 21:13:45 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*new_fd_to_read(int fd)
{
	t_fd	*new;

	new = (t_fd *)malloc(sizeof(t_fd));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->left = NULL;
	new->left_begin = NULL;
	new->next = NULL;
	return (new);
}

char	*ft_strjoin_re(char **s1, char *s2)
{
	char	*joined;
	size_t	j_size;
	size_t	i;

	if (!*s1 || !s2)
		return (NULL);
	i = 0;
	j_size = ft_strlen(*s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(j_size * sizeof(char));
	if (joined == NULL)
		return (NULL);
	j_size = 0;
	while ((*s1)[i])
		joined[j_size++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		joined[j_size++] = s2[i++];
	joined[j_size] = '\0';
	free(*s1);
	return (joined);
}
