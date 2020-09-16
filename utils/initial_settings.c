/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:05:56 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:05:57 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		initial_check(int argc, char **argv, t_vars *vars)
{
	if (argc > 3 || argc < 2)
		ft_exit(EXIT_FAILURE, vars, -2, 0);
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) == 6) && !ft_strncmp("--save", argv[2], 6))
			vars->make_screenshot = 1;
		else
			ft_exit(EXIT_FAILURE, vars, -3, 0);
	}
	map_params_parser(argv[1], vars);
}

void	init_keys(t_vars *vars)
{
	t_is_pressed *keys_status;

	if (!(vars->keys_status))
	{
		if (!(keys_status = malloc(sizeof(t_is_pressed))))
			ft_exit(EXIT_FAILURE, vars, -1, 0);
		keys_status->key_w = 0;
		keys_status->key_a = 0;
		keys_status->key_s = 0;
		keys_status->key_d = 0;
		keys_status->key_left_arrow = 0;
		keys_status->key_right_arrow = 0;
		(vars->keys_status) = keys_status;
	}
}

void		initial_param_set(t_vars *vars, t_data *img)
{
	vars->img_data = img;
	
	vars->win_w = (vars->p)->r_width;
	vars->win_h = (vars->p)->r_height;
	vars->map_w = (vars->map)->max_len_of_line;
	vars->map_h = (vars->map)->y_size;
	vars->sprites_count = parse_sprites_pos_and_count(vars);
}
