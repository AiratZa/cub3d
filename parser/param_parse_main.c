/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parse_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:40 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:35 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	r_param_parse_2(char *line, t_vars *vars, int fd)
{
	t_params *p;

	p = vars->p;
	if (p->r_height < 0)
		ft_exit(EXIT_FAILURE, vars, 51, fd);
	line += number_length(p->r_height);
	while (*line)
	{
		if (*line != ' ')
			ft_exit(EXIT_FAILURE, vars, 52, fd);
		line++;
	}
}

int		r_param_parse(char *line, t_vars *vars, int fd)
{
	t_params *p;

	p = vars->p;
	if (!p->r_has_parsed)
	{
		line += count_spaces_in_row(line);
		if ((*line++ != 'R') || (*line++ != ' '))
			ft_exit(EXIT_FAILURE, vars, 50, fd);
		line += count_spaces_in_row(line);
		p->r_width = ft_atoi(line);
		if (p->r_width < 0)
			ft_exit(EXIT_FAILURE, vars, 51, fd);
		line += number_length(p->r_width);
		if (*line != ' ')
			ft_exit(EXIT_FAILURE, vars, 52, fd);
		line += count_spaces_in_row(line);
		p->r_height = ft_atoi(line);
		r_param_parse_2(line, vars, fd);
		p->r_has_parsed = 1;
	}
	else
		ft_exit(EXIT_FAILURE, vars, 101, fd);
	return (0);
}

int		parse_params(t_vars *vars, int fd)
{
	char *line;

	line = vars->line;
	vars->fd = fd;
	if (ft_strnstr(line, "R ", ft_strlen(line)))
		r_param_parse(line, vars, fd);
	else if (ft_strnstr(line, "NO ", ft_strlen(line)))
		texture_param_parse(line, vars, "NO", 1);
	else if (ft_strnstr(line, "SO ", ft_strlen(line)))
		texture_param_parse(line, vars, "SO", 2);
	else if (ft_strnstr(line, "WE ", ft_strlen(line)))
		texture_param_parse(line, vars, "WE", 3);
	else if (ft_strnstr(line, "EA ", ft_strlen(line)))
		texture_param_parse(line, vars, "EA", 4);
	else if (ft_strnstr(line, "S ", ft_strlen(line)))
		texture_param_parse(line, vars, "S", 5);
	else if (ft_strnstr(line, "F ", ft_strlen(line)))
		rgb_param_parse(line, vars, 'F', fd);
	else if (ft_strnstr(line, "C ", ft_strlen(line)))
		rgb_param_parse(line, vars, 'C', fd);
	else if (!only_spaces_in_line(line))
		ft_exit(EXIT_FAILURE, vars, 50, fd);
	return (0);
}
