/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:57 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/19 08:30:20 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	name_check(char *map_name, t_vars *vars)
{
	int len;

	len = ft_strlen(map_name);
	if (len < 5)
		ft_exit(EXIT_FAILURE, vars, 1, 0);
	if ((map_name[len - 1] != 'b') || (map_name[len - 2] != 'u') ||
		(map_name[len - 3] != 'c') || (map_name[len - 4] != '.'))
		ft_exit(EXIT_FAILURE, vars, 1, 0);
}

void	map_params_parser(char *map_name, t_vars *vars)
{
	int	fd;
	int	only_map_left;

	only_map_left = 0;
	name_check(map_name, vars);
	initial_params(vars);
	if ((fd = open(map_name, O_RDONLY)) < 0)
		ft_exit(EXIT_FAILURE, vars, 1, 0);
	while (!only_map_left && (get_next_line(fd, &(vars->line))))
	{
		parse_params(vars, fd);
		if ((vars->p)->r_has_parsed && (vars->p)->no &&
			(vars->p)->we && (vars->p)->ea &&
			(vars->p)->so && (vars->p)->s && (vars->p)->f_rgb_has_parsed
			&& (vars->p)->c_rgb_has_parsed)
			only_map_left = 1;
		free(vars->line);
		vars->line = NULL;
	}
	map_parser(vars, vars->line, fd);
}
