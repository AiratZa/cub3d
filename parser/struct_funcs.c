/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:27:01 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:42 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

t_map_line	*ft_map_line_new(void *content)
{
	t_map_line *new;

	new = malloc(sizeof(t_map_line));
	if (!new)
		return (NULL);
	new->line = content;
	new->x_size = ft_strlen(content);
	new->next = NULL;
	return (new);
}

t_map_line	*ft_map_line_last(t_map_line *lst)
{
	t_map_line *tmp;

	tmp = lst;
	if (lst == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void		ft_map_line_add_back(t_map_line **lst, t_map_line *new)
{
	t_map_line *tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		tmp = ft_map_line_last(*lst);
		tmp->next = new;
	}
}
