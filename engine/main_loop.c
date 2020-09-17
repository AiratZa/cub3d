/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:49 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:18:03 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_perp_lines(t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->win_w)
	{
		vars->perp_lines[i] = 0;
		i++;
	}
}

int		main_calculations(t_vars *vars)
{
	while ((vars->draw)->x < vars->win_w)
	{
		ray_map_values(vars);
		step_size(vars->draw, vars);
		calc_distance_n_side(vars->draw, vars);
		dist_to_wall_n_start_end_wall(vars);
		draw_floor_n_sky(vars);
		vars->current_texture = get_current_texture(vars);
		draw_wall_line(vars);
		(vars->perp_lines)[(vars->draw)->x] = (vars->draw)->dist_to_wall;
		(vars->draw)->x++;
	}
	return (0);
}

int		main_loop(t_vars *vars)
{
	t_draw draw;

	draw.x = 0;
	vars->draw = &draw;
	key_status_handler(vars);
	init_perp_lines(vars);
	main_calculations(vars);
	sprites_handler(vars);
	if (vars->make_screenshot)
	{
		make_screenshot(vars);
		ft_exit(EXIT_SUCCESS, vars, 0, 0);
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,\
										(vars->img_data)->img_ptr, 0, 0);
	mlx_destroy_image(vars->mlx_ptr, (vars->img_data)->img_ptr);
	create_new_image(vars);
	return (0);
}
