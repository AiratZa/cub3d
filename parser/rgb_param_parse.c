/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_param_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:34 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:15:39 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	rgb_param_parse_3(char *line, t_vars *vars, char param, t_rgb *tmp)
{
	*(tmp->g) = ft_atoi(line);
	if ((*(tmp->g)) < 0)
		ft_exit(EXIT_FAILURE, vars, 51, tmp->fd);
	line += number_length(*(tmp->g));
	line += count_spaces_in_row(line);
	if (*line != ',')
		ft_exit(EXIT_FAILURE, vars, 500, tmp->fd);
	else
		line++;
	line += count_spaces_in_row(line);
	*(tmp->b) = ft_atoi(line);
	if ((*(tmp->b)) < 0)
		ft_exit(EXIT_FAILURE, vars, 51, tmp->fd);
	line += number_length(*(tmp->b));
	line += count_spaces_in_row(line);
	if (*line != '\0')
		ft_exit(EXIT_FAILURE, vars, 501, tmp->fd);
	*(tmp->status) = 1;
}

void	rgb_param_parse_2(char *line, t_vars *vars, char param, t_rgb *tmp)
{
	line += count_spaces_in_row(line);
	if ((*line++ != param) || (*line++ != ' '))
		ft_exit(EXIT_FAILURE, vars, 50, tmp->fd);
	line += count_spaces_in_row(line);
	*(tmp->r) = ft_atoi(line);
	if ((*(tmp->r)) < 0)
		ft_exit(EXIT_FAILURE, vars, 51, tmp->fd);
	line += number_length(*(tmp->r));
	line += count_spaces_in_row(line);
	if (*line != ',')
		ft_exit(EXIT_FAILURE, vars, 500, tmp->fd);
	else
		line++;
	line += count_spaces_in_row(line);
	rgb_param_parse_3(line, vars, param, tmp);
}

int		rgb_param_parse(char *line, t_vars *vars, char param, int fd)
{
	t_rgb		tmp;
	t_params	*p;

	tmp.fd = fd;
	p = vars->p;
	if (param == 'C')
	{
		tmp.status = &(p->c_rgb_has_parsed);
		tmp.r = &(p->c_r);
		tmp.g = &(p->c_g);
		tmp.b = &(p->c_b);
	}
	else if (param == 'F')
	{
		tmp.status = &(p->f_rgb_has_parsed);
		tmp.r = &(p->f_r);
		tmp.g = &(p->f_g);
		tmp.b = &(p->f_b);
	}
	if (!(*(tmp.status)))
		rgb_param_parse_2(line, vars, param, &tmp);
	else
		ft_exit(EXIT_FAILURE, vars, 101, fd);
	return (0);
}
