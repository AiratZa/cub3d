/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:23 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:49:02 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int		count_spaces_in_row(char *line)
{
	int i;

	i = 0;
	while (line[i] && (line[i] == ' '))
		i++;
	return (i);
}

void	initial_params(t_vars *vars)
{
	t_params *params;

	if (!(params = malloc(sizeof(t_params))))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	params->r_has_parsed = 0;
	params->r_width = 0;
	params->r_height = 0;
	params->no = NULL;
	params->we = NULL;
	params->ea = NULL;
	params->so = NULL;
	params->s = NULL;
	params->f_rgb_has_parsed = 0;
	params->c_rgb_has_parsed = 0;
	vars->p = params;
}

int		number_length(int nbr)
{
	int i;

	i = 1;
	if (nbr < 0)
	{
		i += 1;
		nbr *= -1;
	}
	while ((nbr / 10) != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int		only_spaces_in_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlen_sym(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			j++;
		i++;
	}
	return (j);
}
