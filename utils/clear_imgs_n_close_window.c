/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_imgs_n_close_window.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:39:14 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:12:43 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clear_txts_2(t_vars *vars)
{
	if ((vars->textures)->text_e)
	{
		if (((vars->textures)->text_e)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr,
				((vars->textures)->text_e)->img_ptr);
		free((vars->textures)->text_e);
	}
	if ((vars->textures)->text_sprite)
	{
		if (((vars->textures)->text_s)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr,
				((vars->textures)->text_sprite)->img_ptr);
		free((vars->textures)->text_sprite);
	}
}

void	clear_txts(t_vars *vars)
{
	if ((vars->textures)->text_n)
	{
		if (((vars->textures)->text_n)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr,
				((vars->textures)->text_n)->img_ptr);
		free((vars->textures)->text_n);
	}
	if ((vars->textures)->text_s)
	{
		if (((vars->textures)->text_s)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr,
				((vars->textures)->text_s)->img_ptr);
		free((vars->textures)->text_s);
	}
	if ((vars->textures)->text_w)
	{
		if (((vars->textures)->text_w)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr,
				((vars->textures)->text_w)->img_ptr);
		free((vars->textures)->text_w);
	}
	clear_txts_2(vars);
}

int		clear_imgs_n_close_window(t_vars *vars)
{
	if (vars->textures)
	{
		clear_txts(vars);
		free(vars->textures);
	}
	if (vars->img_data)
	{
		if ((vars->img_data)->img_ptr)
			mlx_destroy_image(vars->mlx_ptr, (vars->img_data)->img_ptr);
	}
	if ((vars->win_ptr))
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	return (0);
}
