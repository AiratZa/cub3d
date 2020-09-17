/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:39 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:17:54 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_release_register(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		(vars->keys_status)->key_w = 0;
	else if (keycode == KEY_S)
		(vars->keys_status)->key_s = 0;
	else if (keycode == KEY_A)
		(vars->keys_status)->key_a = 0;
	else if (keycode == KEY_D)
		(vars->keys_status)->key_d = 0;
	else if (keycode == KEY_LEFT_ARROW)
		(vars->keys_status)->key_left_arrow = 0;
	else if (keycode == KEY_RIGHT_ARROW)
		(vars->keys_status)->key_right_arrow = 0;
	return (0);
}

int	key_press_register(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		ft_exit(EXIT_SUCCESS, vars, 0, 0);
	else if (keycode == KEY_W)
		(vars->keys_status)->key_w = 1;
	else if (keycode == KEY_S)
		(vars->keys_status)->key_s = 1;
	else if (keycode == KEY_A)
		(vars->keys_status)->key_a = 1;
	else if (keycode == KEY_D)
		(vars->keys_status)->key_d = 1;
	else if (keycode == KEY_LEFT_ARROW)
		(vars->keys_status)->key_left_arrow = 1;
	else if (keycode == KEY_RIGHT_ARROW)
		(vars->keys_status)->key_right_arrow = 1;
	return (0);
}

int	button_press_register(t_vars *vars)
{
	return (ft_exit(EXIT_SUCCESS, vars, 0, 0));
}
