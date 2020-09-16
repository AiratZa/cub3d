/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:05:51 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:05:52 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_textures(t_vars *vars)
{
	if (!(vars->textures = malloc(sizeof(t_textures))))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	(vars->textures)->text_n = NULL;
	(vars->textures)->text_s = NULL;
	(vars->textures)->text_w = NULL;
	(vars->textures)->text_e = NULL;
	(vars->textures)->text_sprite = NULL;
}

int	load_texture(char *file_name, t_vars *vars, char side)
{
	t_data *txt;
	if (!(txt = malloc(sizeof(t_data))))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	txt->img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,	file_name,\
					&(txt->width), &(txt->height));
	if (!(txt->img_ptr))
	{
		free(txt);
		ft_exit(EXIT_FAILURE, vars, 1001, 0);
	}
	txt->addr = mlx_get_data_addr(txt->img_ptr, &(txt->bits_per_pixel),\
				&(txt->size_line), &(txt->endian));
	if (side == 'N')
		(vars->textures)->text_n = txt;
	else if (side == 'W')
		(vars->textures)->text_w = txt;
	else if (side == 'E')
		(vars->textures)->text_e = txt;
	else if (side == 'S')
		(vars->textures)->text_s = txt;
	else if (side == 's')
		(vars->textures)->text_sprite = txt;
	if (!(txt->addr))
		ft_exit(EXIT_FAILURE, vars, 1001, 0);
	return (0);
}

int	get_textures(t_vars *vars)
{
	init_textures(vars);
	load_texture((vars->p)->NO, vars, 'N');
	load_texture((vars->p)->WE, vars, 'W');
	load_texture((vars->p)->EA, vars, 'E');
	load_texture((vars->p)->SO, vars, 'S');
	load_texture((vars->p)->S, vars, 's');
	return (0);
}
