/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:46 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:18:00 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_map_values(t_vars *vars)
{
	(vars->draw)->camera_x = 2 * (vars->draw)->x / (double)vars->win_w - 1;
	(vars->draw)->ray_dir_x = vars->dir_x + vars->plane_x *\
								(vars->draw)->camera_x;
	(vars->draw)->ray_dir_y = vars->dir_y + vars->plane_y *\
								(vars->draw)->camera_x;
	(vars->draw)->map_x_pos = (int)(vars->pos_x);
	(vars->draw)->map_y_pos = (int)(vars->pos_y);
	(vars->draw)->delta_dist_x = fabs(1 / (vars->draw)->ray_dir_x);
	(vars->draw)->delta_dist_y = fabs(1 / (vars->draw)->ray_dir_y);
}

void	step_size(t_draw *draw, t_vars *vars)
{
	if (draw->ray_dir_x < 0)
	{
		draw->step_x = -1;
		draw->side_dist_x = (vars->pos_x - draw->map_x_pos) *\
							draw->delta_dist_x;
	}
	else
	{
		draw->step_x = 1;
		draw->side_dist_x = (draw->map_x_pos + 1.0 - vars->pos_x) *\
							draw->delta_dist_x;
	}
	step_size_2(draw, vars);
}

void	step_size_2(t_draw *draw, t_vars *vars)
{
	if (draw->ray_dir_y < 0)
	{
		draw->step_y = -1;
		draw->side_dist_y = (vars->pos_y - draw->map_y_pos) *\
							draw->delta_dist_y;
	}
	else
	{
		draw->step_y = 1;
		draw->side_dist_y = (draw->map_y_pos + 1.0 - vars->pos_y) *\
							draw->delta_dist_y;
	}
}

void	calc_distance_n_side(t_draw *draw, t_vars *vars)
{
	int hit;

	hit = 0;
	while (!hit)
	{
		set_wall_side(draw, vars);
		if ((vars->m_arr)[draw->map_y_pos][draw->map_x_pos] == '1')
			hit = 1;
	}
}

void	set_wall_side(t_draw *draw, t_vars *vars)
{
	if (draw->side_dist_x < draw->side_dist_y)
	{
		draw->side_dist_x += draw->delta_dist_x;
		draw->map_x_pos += draw->step_x;
		if (draw->ray_dir_x < 0)
			vars->w_side = 'W';
		else
			vars->w_side = 'E';
	}
	else
	{
		draw->side_dist_y += draw->delta_dist_y;
		draw->map_y_pos += draw->step_y;
		if (draw->ray_dir_y < 0)
			vars->w_side = 'N';
		else
			vars->w_side = 'S';
	}
}
