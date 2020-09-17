/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:05:58 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:23 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	check_to_top(int x, int y, t_vars *vars)
{
	int opened;
	int t_y;

	t_y = y;
	opened = 0;
	while (t_y >= 0)
	{
		if ((vars->m_arr)[t_y][x] == '1')
			return (0);
		else if ((((vars->m_arr)[t_y][x] == '0') ||
			((vars->m_arr)[t_y][x] == '2') ||
			((vars->m_arr)[t_y][x] == 'N') ||
			((vars->m_arr)[t_y][x] == 'S') ||
			((vars->m_arr)[t_y][x] == 'E') ||
			((vars->m_arr)[t_y][x] == 'W')))
			opened = 1;
		else if (((vars->m_arr)[t_y][x] == ' ') && opened)
			return (-1);
		t_y--;
	}
	if (opened)
		return (-1);
	return (0);
}

int	check_to_bot(int x, int y, t_vars *vars)
{
	int opened;
	int t_y;

	t_y = y;
	opened = 0;
	while (t_y < (vars->map)->y_size)
	{
		if ((vars->m_arr)[t_y][x] == '1')
			return (0);
		else if ((((vars->m_arr)[t_y][x] == '0') ||
			((vars->m_arr)[t_y][x] == '2') ||
			((vars->m_arr)[t_y][x] == 'N') ||
			((vars->m_arr)[t_y][x] == 'S') ||
			((vars->m_arr)[t_y][x] == 'E') ||
			((vars->m_arr)[t_y][x] == 'W')))
			opened = 1;
		else if (((vars->m_arr)[t_y][x] == ' ') && opened)
			return (-1);
		t_y++;
	}
	if (opened)
		return (-1);
	return (0);
}

int	check_to_left(int x, int y, t_vars *vars)
{
	int		opened;
	int		t_x;
	char	*t_line;

	t_x = x;
	opened = 0;
	t_line = (vars->m_arr)[y];
	while (t_x >= 0)
	{
		if (t_line[t_x] == '1')
			return (0);
		else if (((t_line[t_x] == '0') || (t_line[t_x] == '2') ||
			(t_line[t_x] == 'N') || (t_line[t_x] == 'S') ||
			(t_line[t_x] == 'E') || (t_line[t_x] == 'W')))
			opened = 1;
		else if ((t_line[t_x] == ' ') && opened)
			return (-1);
		t_x--;
	}
	if (opened)
		return (-1);
	return (0);
}

int	check_to_right(int x, int y, t_vars *vars)
{
	int		opened;
	int		t_x;
	char	*t_line;

	t_x = x;
	opened = 0;
	t_line = (vars->m_arr)[y];
	while (t_x < ft_strlen(t_line))
	{
		if (t_line[t_x] == '1')
			return (0);
		else if (((t_line[t_x] == '0') || (t_line[t_x] == '2') ||
			(t_line[t_x] == 'N') || (t_line[t_x] == 'S') ||
			(t_line[t_x] == 'E') || (t_line[t_x] == 'W')))
			opened = 1;
		else if (t_x < ft_strlen(t_line) && (t_line[t_x] == ' ') && opened)
			return (-1);
		t_x++;
	}
	if (opened)
		return (-1);
	return (0);
}

int	check_map_borders(t_vars *vars)
{
	int x;
	int y;
	int len;

	y = 0;
	while (y < (vars->map)->y_size)
	{
		x = 0;
		len = ft_strlen((vars->m_arr)[y]);
		while (x < len)
		{
			if ((vars->m_arr)[y][x] != ' ' && (vars->m_arr)[y][x] != '1')
			{
				if (check_to_top(x, y, vars) || check_to_left(x, y, vars) ||
				check_to_right(x, y, vars) || check_to_bot(x, y, vars))
					ft_exit(EXIT_FAILURE, vars, 5, 0);
			}
			x++;
		}
		y++;
	}
	return (0);
}
