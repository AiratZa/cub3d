/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 19:07:08 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:45:31 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

/*
** param_name -> number
** NO -> 1
** SO -> 2
** WE -> 3
** EA -> 4
** S  -> 5
*/

void	put_in_struct(t_vars *vars, int param_nbr, char *temp_ptr)
{
	if (param_nbr == 1)
		vars->p->no = temp_ptr;
	else if (param_nbr == 2)
		vars->p->so = temp_ptr;
	else if (param_nbr == 3)
		vars->p->we = temp_ptr;
	else if (param_nbr == 4)
		vars->p->ea = temp_ptr;
	else if (param_nbr == 5)
		vars->p->s = temp_ptr;
}

void	texture_param_parse2(char *line, t_vars *vars,
								int param_nbr, char *temp_ptr)
{
	line += count_spaces_in_row(line);
	if ((param_nbr >= 1) && (param_nbr <= 4))
	{
		if ((*line++ != (vars->tmp_line)[0]) ||
			(*line++ != (vars->tmp_line)[1]) || (*line++ != ' '))
			ft_exit(EXIT_FAILURE, vars, 50, vars->fd);
	}
	else if (param_nbr == 5)
	{
		if ((*line++ != (vars->tmp_line)[0]) || (*line++ != ' '))
			ft_exit(EXIT_FAILURE, vars, 50, vars->fd);
	}
	line += count_spaces_in_row(line);
	while (line[vars->tmp])
		vars->tmp++;
	if (!(temp_ptr = ft_substr(line, 0, vars->tmp)))
		ft_exit(EXIT_FAILURE, vars, -1, vars->fd);
	line += vars->tmp;
	line += count_spaces_in_row(line);
	if (*line)
		ft_exit(EXIT_FAILURE, vars, 52, vars->fd);
	put_in_struct(vars, param_nbr, temp_ptr);
}

int		texture_param_parse(char *line, t_vars *vars,
								char *param_name, int param_nbr)
{
	char *temp_ptr;

	vars->tmp_line = param_name;
	if (param_nbr == 1)
		temp_ptr = vars->p->no;
	else if (param_nbr == 2)
		temp_ptr = vars->p->so;
	else if (param_nbr == 3)
		temp_ptr = vars->p->we;
	else if (param_nbr == 4)
		temp_ptr = vars->p->ea;
	else if (param_nbr == 5)
		temp_ptr = vars->p->s;
	if (!temp_ptr)
		texture_param_parse2(line, vars, param_nbr, temp_ptr);
	else
		ft_exit(EXIT_FAILURE, vars, 101, vars->fd);
	return (0);
}
