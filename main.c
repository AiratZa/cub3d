/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:00:10 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:18:27 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_vars_img(t_vars *vars, t_data *img)
{
	vars->tmp = 0;
	vars->fd = 0;
	vars->tmp_line = NULL;
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->img_data = NULL;
	vars->p = NULL;
	vars->map = NULL;
	vars->textures = NULL;
	vars->current_texture = NULL;
	vars->draw = NULL;
	vars->keys_status = NULL;
	vars->sprites = NULL;
	vars->perp_lines = NULL;
	vars->line = NULL;
	vars->m_arr = NULL;
	vars->make_screenshot = 0;
	img->img_ptr = NULL;
	img->addr = NULL;
}

int		main(int argc, char **argv)
{
	t_vars vars;
	t_data img;

	init_vars_img(&vars, &img);
	initial_check(argc, argv, &vars);
	initial_param_set(&vars, &img);
	if (!(vars.mlx_ptr = mlx_init()))
		ft_exit(EXIT_FAILURE, &vars, 1000, 0);
	initial_param_set_2(&vars, &img);
	init_keys(&vars);
	mlx_hook(vars.win_ptr, 2, 1L << 0, &key_press_register, &vars);
	mlx_hook(vars.win_ptr, 3, 1L << 1, &key_release_register, &vars);
	mlx_hook(vars.win_ptr, 17, 1L << 17, &button_press_register, &vars);
	mlx_loop_hook(vars.mlx_ptr, &main_loop, &vars);
	mlx_loop(vars.mlx_ptr);
	ft_exit(EXIT_SUCCESS, &vars, 0, 0);
}
