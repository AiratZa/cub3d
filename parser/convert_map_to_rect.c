/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_to_rect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:57:37 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:14 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int		check_max_len_line(t_map *map)
{
	int			i;
	int			tmp;
	int			max;
	t_map_line	*tmp2;

	i = 0;
	tmp = 0;
	max = 0;
	tmp2 = map->start;
	while (i < map->y_size)
	{
		tmp = ft_strlen(tmp2->line);
		if (tmp > max)
			max = tmp;
		tmp2 = tmp2->next;
		i++;
	}
	return (max);
}

void	malloc_arr(t_vars *vars)
{
	int	i;

	i = 0;
	if (!((vars->m_arr) = malloc(sizeof(char *) * (vars->map)->y_size)))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	while (i < (vars->map)->y_size)
	{
		(vars->m_arr)[i] = NULL;
		i++;
	}
	i = 0;
	while (i < (vars->map)->y_size)
	{
		if (!((vars->m_arr)[i] = malloc(sizeof(char) *
				((vars->map)->max_len_of_line + 1))))
			ft_exit(EXIT_FAILURE, vars, -1, 0);
		i++;
	}
}

void	ft_copy_line(t_vars *vars, t_map_line *tmp_line)
{
	while ((vars->j) < (vars->map)->max_len_of_line)
	{
		(vars->m_arr)[(vars->i)][(vars->j)] = (tmp_line->line)[(vars->j)];
		(vars->j)++;
	}
	(vars->m_arr)[(vars->i)][(vars->j)] = '\0';
}

void	ft_resize_line(t_vars *vars, t_map_line *tmp_line)
{
	while ((vars->j) < (vars->len))
	{
		(vars->m_arr)[(vars->i)][(vars->j)] = (tmp_line->line)[(vars->j)];
		(vars->j)++;
	}
	while ((vars->j) < ((vars->map)->max_len_of_line))
	{
		(vars->m_arr)[(vars->i)][(vars->j)] = ' ';
		(vars->j)++;
	}
	(vars->m_arr)[(vars->i)][(vars->j)] = '\0';
}

int		convert_map_to_rectangle(t_vars *vars)
{
	t_map_line *tmp_line;

	(vars->i) = 0;
	tmp_line = (vars->map)->start;
	(vars->map)->max_len_of_line = check_max_len_line(vars->map);
	malloc_arr(vars);
	while ((vars->i) < (vars->map)->y_size)
	{
		(vars->j) = 0;
		(vars->len) = ft_strlen((tmp_line->line));
		if ((vars->len) < (vars->map)->max_len_of_line)
			ft_resize_line(vars, tmp_line);
		else
			ft_copy_line(vars, tmp_line);
		(vars->i)++;
		tmp_line = tmp_line->next;
	}
	return (0);
}
