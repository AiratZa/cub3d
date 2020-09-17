/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:03:28 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:05:26 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_data *data, size_t x, size_t y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		my_mlx_pixel_get(t_data *data, size_t x, size_t y)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	return (*(int*)dst);
}



int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		create_new_image(t_vars *vars)
{
	if (!((vars->img_data)->img_ptr =\
		mlx_new_image(vars->mlx_ptr, vars->win_w, vars->win_h)))
		ft_exit(EXIT_FAILURE, vars, 1001, 0);
	if (!((vars->img_data)->addr = mlx_get_data_addr((vars->img_data)->img_ptr,
		&((vars->img_data)->bits_per_pixel), &((vars->img_data)->size_line),
		&((vars->img_data)->endian))))
		ft_exit(EXIT_FAILURE, vars, 1001, 0);
	return (0);
}
