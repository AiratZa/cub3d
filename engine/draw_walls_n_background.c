/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_n_background.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:37 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:06:38 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dist_to_wall_n_start_end_wall(t_vars *vars)
{
	if (vars->w_side == 'W' || vars->w_side == 'E')
		(vars->draw)->dist_to_wall = ((vars->draw)->map_x_pos - vars->pos_x +\
		(1 - (vars->draw)->step_x) / 2) / (vars->draw)->ray_dir_x;
	else
		(vars->draw)->dist_to_wall = ((vars->draw)->map_y_pos -\
			vars->pos_y + (1 - (vars->draw)->step_y) / 2) /\
			(vars->draw)->ray_dir_y;
	(vars->draw)->wall_height = (int)(vars->win_h / vars->draw->dist_to_wall);
	(vars->draw)->draw_start = vars->win_h / 2 - (vars->draw)->wall_height / 2;
	if ((vars->draw)->draw_start < 0)
		(vars->draw)->draw_start = 0;
	(vars->draw)->draw_end = (vars->draw)->wall_height / 2 + vars->win_h / 2;
	if ((vars->draw)->draw_end >= vars->win_h)
		(vars->draw)->draw_end = vars->win_h - 1;
}

void	draw_floor_n_sky(t_vars *vars)
{
	int tmp;

	tmp = -1;
	while (tmp++ < (vars->draw)->draw_start)
		my_mlx_pixel_put(vars->img_data, (vars->draw)->x, tmp,\
			create_rgb((vars->p)->c_r, (vars->p)->c_g, (vars->p)->c_b));
	tmp = (vars->draw)->draw_end;
	while (tmp < vars->win_h)
	{
		my_mlx_pixel_put(vars->img_data, (vars->draw)->x, tmp,\
				create_rgb((vars->p)->f_r, (vars->p)->f_g, (vars->p)->f_b));
		tmp++;
	}
}

t_data	*get_current_texture(t_vars *vars)
{
	if (vars->w_side == 'N')
		return (vars->textures->text_n);
	else if (vars->w_side == 'W')
		return (vars->textures->text_w);
	else if (vars->w_side == 'E')
		return (vars->textures->text_e);
	else if (vars->w_side == 'S')
		return (vars->textures->text_s);
	return (NULL);
}

void	draw_wall_line(t_vars *vars)
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;

	if (vars->w_side == 'W' || vars->w_side == 'E')
		wall_x = vars->pos_y + (vars->draw)->dist_to_wall *\
				(vars->draw)->ray_dir_y;
	else
		wall_x = vars->pos_x + (vars->draw)->dist_to_wall *\
				(vars->draw)->ray_dir_x;
	wall_x -= floor((wall_x));
	tex_x = (int)(wall_x * (double)((vars->current_texture)->width));
	if (vars->w_side == 'E' || vars->w_side == 'N')
		tex_x = (vars->current_texture)->width - tex_x - 1;
	step = 1.0 * (vars->current_texture)->height /\
					(vars->draw)->wall_height;
	tex_pos = ((vars->draw)->draw_start - vars->win_h / 2 +\
					(vars->draw)->wall_height / 2) * step;
	(vars->draw)->y = (vars->draw)->draw_start;
	draw_line(vars, tex_pos, step, tex_x);
}

void	draw_line(t_vars *vars, double tex_pos, double step, int tex_x)
{
	int color;

	while ((vars->draw)->y < (vars->draw)->draw_end)
	{
		tex_pos += step;
		color =\
		my_mlx_pixel_get(vars->current_texture, tex_x, ((int)tex_pos - 1));
		my_mlx_pixel_put(vars->img_data,\
						(vars->draw)->x, (vars->draw)->y, color);
		(vars->draw)->y++;
	}
}
