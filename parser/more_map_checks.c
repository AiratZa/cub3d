/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:15:37 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:32 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

/*
** Except for the map content, each type of element can be separated by one or
** more empty line(s)
*/

void	map_line_len_append_and_check(t_vars *vars)
{
	int i;
	int count_empty_lines;
	int len;

	i = 0;
	count_empty_lines = 0;
	len = 0;
	while (i < (vars->map)->y_size)
	{
		len = ft_strlen_sym((vars->m_arr)[i]);
		if (len && count_empty_lines)
			ft_exit(EXIT_FAILURE, vars, 3, 0);
		if (!len)
			count_empty_lines++;
		i++;
	}
}

void	check_chars_and_entry_point_2(t_vars *vars, char tmp_char, int *found)
{
	if ((tmp_char != ' ') && (tmp_char != '0') && (tmp_char != '1') &&
	(tmp_char != '2') && (tmp_char != 'N') && (tmp_char != 'S') &&
	(tmp_char != 'E') && (tmp_char != 'W'))
		ft_exit(EXIT_FAILURE, vars, 4, 0);
	if ((tmp_char == 'N') || (tmp_char == 'S') ||\
	(tmp_char == 'E') || (tmp_char == 'W'))
	{
		if (*found)
			ft_exit(EXIT_FAILURE, vars, 400, 0);
		else
		{
			(vars->m_arr)[(vars->i)][(vars->j)] = '0';
			(vars->map)->player_x_pos = (vars->j);
			(vars->map)->player_y_pos = (vars->i);
			(vars->map)->player_dir = tmp_char;
			(*found) = 1;
		}
	}
}

void	check_chars_and_entry_point(t_vars *vars)
{
	char	tmp_char;
	int		found;

	(vars->i) = 0;
	found = 0;
	while ((vars->i) < (vars->map)->y_size)
	{
		(vars->j) = 0;
		while ((vars->m_arr)[(vars->i)][(vars->j)] &&
			(tmp_char = (vars->m_arr)[(vars->i)][(vars->j)]))
		{
			check_chars_and_entry_point_2(vars, tmp_char, &found);
			(vars->j)++;
		}
		(vars->i)++;
	}
	if (!found)
		ft_exit(EXIT_FAILURE, vars, 401, 0);
}
