/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:04 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:06:05 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void free_params(t_vars *vars)
{
	if (vars->p->NO)
		free(vars->p->NO);
	if ((vars->p)->SO)
		free((vars->p)->SO);
	if ((vars->p)->WE)
		free((vars->p)->WE);
	if ((vars->p)->EA)
		free((vars->p)->EA);
	if ((vars->p)->S)
		free((vars->p)->S);
}

void	free_arr(t_vars *vars)
{
	int i;

	i = 0;
	while (i < (vars->map)->y_size)
	{
		free((vars->m_arr)[i]);
		i++;
	}
}

void	free_map(t_vars *vars)
{
	t_map_line *tmp;

	tmp = (vars->map)->start;
	while (tmp)
	{
		tmp = ((vars->map)->start)->next;
		// printf("==%s\n", (vars->map)->start->line);
		free(((vars->map)->start)->line);
		free(((vars->map)->start));
		(vars->map)->start = tmp;
	}
}

void free_spr(t_vars *vars)
{
	t_sprites_pos *tmp;

	while(vars->sprites)
	{
		tmp = (vars->sprites);;
		vars->sprites = tmp->next;
		free(tmp);
	}
}

void clear_txts(t_vars *vars)
{
	if ((vars->textures)->text_n)
	{
		if (((vars->textures)->text_n)->img_ptr)
    		mlx_destroy_image(vars->mlx_ptr, ((vars->textures)->text_n)->img_ptr);
		free((vars->textures)->text_n);
	}
	if ((vars->textures)->text_s)
	{
		if (((vars->textures)->text_s)->img_ptr)
    		mlx_destroy_image(vars->mlx_ptr, ((vars->textures)->text_s)->img_ptr);
		free((vars->textures)->text_s);
	}
	if ((vars->textures)->text_w)
	{
		if (((vars->textures)->text_w)->img_ptr)
	    	mlx_destroy_image(vars->mlx_ptr, ((vars->textures)->text_w)->img_ptr);
		free((vars->textures)->text_w);
	}
	if ((vars->textures)->text_e)
	{
		if (((vars->textures)->text_e)->img_ptr)
    		mlx_destroy_image(vars->mlx_ptr, ((vars->textures)->text_e)->img_ptr);
		free((vars->textures)->text_e);
	}
	if ((vars->textures)->text_sprite)
	{
		if (((vars->textures)->text_s)->img_ptr)
    		mlx_destroy_image(vars->mlx_ptr, ((vars->textures)->text_sprite)->img_ptr);
		free((vars->textures)->text_sprite);
	}
}

int             clear_imgs_n_close_window(t_vars *vars)
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

/*
** -101 Cant close file for saving screenshot
** -100 Cant open file for saving screenshot
** -3 second param is not "--save"
** -2 number of params not in (2, 3)
** -1 malloc returned NULL
** 1 map file open error
** 2 map file close error
** 3 empty line separator in map
** 50 Non-mentioned parameter found in .cub file
** 51 Negative param is found
** 52 One of parameter format is incorrect
** 101 Param was parsed or non-mentioned param
** 400 Count of start point more than 1
** 401 Start point is not found
** 500 RGB Parameters is not separated by commas
** 501 RGB Parameters is incorrect
** 1000 mlx_init failed
** 1001 mlx_new_image failed
*/

int	ft_exit(int status, t_vars *vars, int situation, int fd)
{
	if (fd > 0)
		close(fd);
	if (status == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", 1);
		if (situation == (-1))
			ft_putstr_fd("Error occured when allocate the memory\n", 1);
		else if (situation == (-2))
			ft_putstr_fd("Number of params is less or more than required\n\
You must provide path to map params.\n\
You can also provide second param --save to save screenshot \
instead of opening a window with a game.", 1);
		else if (situation == (-3))
			ft_putstr_fd("Second provided param to programm is not '--save'. Behavior is undefined :(\n", 1);
		else if (situation == (-100))
			ft_putstr_fd("Cant open file for writing/rewriting screenshot info in bmp file :(\n", 1);
		else if (situation == (-101))
			ft_putstr_fd("Error occured when close file for writing/rewriting screenshot info in bmp file :(\n", 1);
		else if (situation == 1)
			ft_putstr_fd("Error occured when open map config file\n", 1);
		else if (situation == 2)
			ft_putstr_fd("Error occured when close map config file\n", 1);
		else if (situation == 3)
			ft_putstr_fd("Map cant be separated by one or more empty line(s)\n", 1);
		else if (situation == 4)
			ft_putstr_fd("Incorrect char in map is found\n", 1);
		else if (situation == 5)
			ft_putstr_fd("In one of the side of map point map dont or cant exist correct border\n", 1);
		else if (situation == 50)
        	ft_putstr_fd("Non-mentioned parameter found in .cub file\n", 1);
		else if (situation == 51)
        	ft_putstr_fd("No one of parameters should be negative\n", 1);
		else if (situation == 52)
        	ft_putstr_fd("One of parameters format is incorrect\n", 1);
		else if (situation == 101)
        	ft_putstr_fd("One of parameters already was parsed or Non-mentioned parameter is found\n", 1);
		else if (situation == 400)
        	ft_putstr_fd("Count of start point more than 1\n", 1);
		else if (situation == 401)
        	ft_putstr_fd("Start point is not found\n", 1);
		else if (situation == 500)
        	ft_putstr_fd("RGB Parameters is not separated by commas\n", 1);
		else if (situation == 501)
        	ft_putstr_fd("RGB Parameters is incorrect\n", 1);
		else if (situation == 1000)
        	ft_putstr_fd("MLX initialization is failed\n", 1);
		else if (situation == 1001)
        	ft_putstr_fd("MLX new image initialization is failed\n", 1);


	}
	if (vars)
	{
		if (vars->m_arr)
		{
			free_arr(vars);
			free(vars->m_arr);
		}
		if (vars->line)
			free(vars->line);
		if (vars->p)
		{
			free_params(vars);
			free(vars->p);
		}
		if (vars->map)
		{
			free_map(vars);
			free(vars->map);
		}
		if (vars->sprites)
		{
			free_spr(vars);
			free(vars->sprites);
		}
		if (vars->mlx_ptr)
			clear_imgs_n_close_window(vars);
		if (vars->perp_lines)
			free(vars->perp_lines);
		if (vars->keys_status)
			free(vars->keys_status);
	}
	exit(status);
	return (status);
}
