/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_status_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:43 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:17:57 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrow_keys_handler(t_vars *vars)
{
	int tmp_x;
	int tmp_y;

	if ((vars->keys_status)->key_left_arrow)
	{
		tmp_x = (int)(vars->pos_x - vars->plane_x * vars->move_speed);
		if ((vars->m_arr)[(int)(vars->pos_y)][tmp_x] == '0')
			vars->pos_x -= vars->plane_x * vars->move_speed;
		tmp_y = (int)(vars->pos_y - vars->plane_y * vars->move_speed);
		if ((vars->m_arr)[tmp_y][(int)(vars->pos_x)] == '0')
			vars->pos_y -= vars->plane_y * vars->move_speed;
	}
	if ((vars->keys_status)->key_right_arrow)
	{
		tmp_x = (int)(vars->pos_x + vars->plane_x * vars->move_speed);
		if ((vars->m_arr)[(int)(vars->pos_y)][tmp_x] == '0')
			vars->pos_x += vars->plane_x * vars->move_speed;
		tmp_y = (int)(vars->pos_y + vars->plane_y * vars->move_speed);
		if ((vars->m_arr)[tmp_y][(int)(vars->pos_x)] == '0')
			vars->pos_y += vars->plane_y * vars->move_speed;
	}
}

void	w_s_keys_handler(t_vars *vars)
{
	int tmp_x;
	int tmp_y;

	if ((vars->keys_status)->key_w)
	{
		tmp_x = (int)(vars->pos_x + vars->dir_x * vars->move_speed);
		if ((vars->m_arr)[(int)(vars->pos_y)][tmp_x] == '0')
			vars->pos_x += vars->dir_x * vars->move_speed;
		tmp_y = (int)(vars->pos_y + vars->dir_y * vars->move_speed);
		if ((vars->m_arr)[tmp_y][(int)(vars->pos_x)] == '0')
			vars->pos_y += vars->dir_y * vars->move_speed;
	}
	if ((vars->keys_status)->key_s)
	{
		tmp_x = (int)(vars->pos_x - vars->dir_x * vars->move_speed);
		if ((vars->m_arr)[(int)(vars->pos_y)][tmp_x] == '0')
			vars->pos_x -= vars->dir_x * vars->move_speed;
		tmp_y = (int)(vars->pos_y - vars->dir_y * vars->move_speed);
		if ((vars->m_arr)[tmp_y][(int)(vars->pos_x)] == '0')
			vars->pos_y -= vars->dir_y * vars->move_speed;
	}
}

void	a_key_handler(t_vars *vars)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-1 * (vars->rot_speed)) -\
	vars->dir_y * sin(-1 * (vars->rot_speed));
	vars->dir_y = old_dir_x * sin(-1 * (vars->rot_speed)) +\
	vars->dir_y * cos(-1 * (vars->rot_speed));
	old_plane_x = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-1 * vars->rot_speed) -\
	vars->plane_y * sin(-1 * (vars->rot_speed));
	vars->plane_y = old_plane_x * sin(-1 * (vars->rot_speed)) +\
	vars->plane_y * cos(-1 * (vars->rot_speed));
}

void	a_d_keys_handler(t_vars *vars)
{
	double old_dir_x;
	double old_plane_x;

	if ((vars->keys_status)->key_a)
		a_key_handler(vars);
	if ((vars->keys_status)->key_d)
	{
		old_dir_x = vars->dir_x;
		vars->dir_x = vars->dir_x * cos(vars->rot_speed) -\
		vars->dir_y * sin(vars->rot_speed);
		vars->dir_y = old_dir_x * sin(vars->rot_speed) +\
		vars->dir_y * cos(vars->rot_speed);
		old_plane_x = vars->plane_x;
		vars->plane_x = vars->plane_x * cos(vars->rot_speed) -\
		vars->plane_y * sin(vars->rot_speed);
		vars->plane_y = old_plane_x * sin(vars->rot_speed) +\
		vars->plane_y * cos(vars->rot_speed);
	}
}

void	key_status_handler(t_vars *vars)
{
	if ((vars->keys_status)->key_w ||\
		(vars->keys_status)->key_s)
		w_s_keys_handler(vars);
	if ((vars->keys_status)->key_a ||\
		(vars->keys_status)->key_d)
		a_d_keys_handler(vars);
	if ((vars->keys_status)->key_left_arrow ||\
		(vars->keys_status)->key_right_arrow)
		arrow_keys_handler(vars);
}
