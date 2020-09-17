/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:52 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:28 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	map_parser_2(t_vars *vars)
{
	convert_map_to_rectangle(vars);
	testing(vars->m_arr, vars);
	check_chars_and_entry_point(vars);
	map_line_len_append_and_check(vars);
	check_map_borders(vars);
}

void	get_new_line(t_vars *vars, char *line, int fd, int *inc)
{
	t_map_line	*tmp;

	if (!(tmp = ft_map_line_new(line)))
		ft_exit(EXIT_FAILURE, vars, -1, fd);
	ft_map_line_add_back(&((vars->map)->start), tmp);
	(*inc)++;
}

int		init_map(t_vars *vars)
{
	if (!(vars->map = malloc(sizeof(t_map))))
		return (-1);
	(vars->map)->start = NULL;
	(vars->map)->arr_ptr = NULL;
	return (0);
}

int		map_parser(t_vars *vars, char *line, int fd)
{
	int i;

	i = 0;
	if (init_map(vars) == (-1))
		ft_exit(EXIT_FAILURE, vars, -1, fd);
	while ((get_next_line(fd, &(vars->line))) > 0 &&
			(ft_strlen(vars->line) == 0))
	{
		free(vars->line);
		vars->line = NULL;
	}
	if (vars->line)
	{
		if (!((vars->map)->start = ft_map_line_new(vars->line)))
			ft_exit(EXIT_FAILURE, vars, -1, fd);
		i++;
		while ((get_next_line(fd, &(vars->line))) > 0)
			get_new_line(vars, vars->line, fd, &i);
	}
	(vars->map)->y_size = i;
	if (close(fd))
		ft_exit(EXIT_FAILURE, vars, 2, 0);
	map_parser_2(vars);
	return (0);
}
