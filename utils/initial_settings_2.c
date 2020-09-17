/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_settings_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:00 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:12:31 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	configure_screen_size(void *mlx_ptr, int *x, int *y)
{
	int sizex;
	int sizey;

	sizex = 1;
	sizey = 1;
	mlx_get_screen_size(mlx_ptr, &sizex, &sizey);
	if ((*x > sizex) || (*y > sizey))
	{
		*x = sizex;
		*y = sizey;
	}
}

void	set_initial_player_pos_n_speed(t_vars *vars)
{
	vars->pos_x = (vars->map)->player_x_pos + 0.5;
	vars->pos_y = (vars->map)->player_y_pos + 0.5;
	vars->move_speed = 0.09;
	vars->rot_speed = 0.09;
}

void	set_dir_n_plane_2(t_vars *vars, char player_dir)
{
	if (player_dir == 'W')
	{
		vars->dir_x = -1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = -0.66;
	}
	else if (player_dir == 'S')
	{
		vars->dir_x = 0;
		vars->dir_y = 1;
		vars->plane_x = -0.66;
		vars->plane_y = 0;
	}
}

void	set_dir_n_plane(t_vars *vars, char player_dir)
{
	if (player_dir == 'N')
	{
		vars->dir_x = 0;
		vars->dir_y = -1;
		vars->plane_x = 0.66;
		vars->plane_y = 0;
	}
	else if (player_dir == 'E')
	{
		vars->dir_x = 1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = 0.66;
	}
	else if (player_dir == 'W' ||
			player_dir == 'S')
		set_dir_n_plane_2(vars, player_dir);
}

int		initial_param_set_2(t_vars *vars, t_data *img)
{
	configure_screen_size(vars->mlx_ptr, &(vars->win_w), &(vars->win_h));
	create_new_image(vars);
	if (!(vars->win_ptr = mlx_new_window(vars->mlx_ptr,
								vars->win_w, vars->win_h, "cub3D")))
		ft_exit(EXIT_FAILURE, vars, 1002, 0);
	get_textures(vars);
	if (!(vars->perp_lines = malloc(sizeof(double) * vars->win_w)))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	set_dir_n_plane(vars, (vars->map)->player_dir);
	set_initial_player_pos_n_speed(vars);
	return (0);
}
