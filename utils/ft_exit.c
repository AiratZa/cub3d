/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:04 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:11:06 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	print_error_2(int situation)
{
	if (situation == 5)
		ft_putstr_fd("In 1 of side of map point dont/cant exist border\n", 1);
	else if (situation == 50)
		ft_putstr_fd("Non-mentioned parameter found in .cub file\n", 1);
	else if (situation == 51)
		ft_putstr_fd("No one of parameters should be negative\n", 1);
	else if (situation == 52)
		ft_putstr_fd("One of parameters format is incorrect\n", 1);
	else if (situation == 101)
		ft_putstr_fd("One of params already was parsed or \
Non-mentioned parameter is found\n", 1);
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

void	print_error(int situation)
{
	if (situation == (-1))
		ft_putstr_fd("Error occured when allocate the memory\n", 1);
	else if (situation == (-2))
		ft_putstr_fd("Number of params is less or more than required\n\
You must provide path to map params.\n\
You can also provide second param --save to save screenshot \
instead of opening a window with a game.", 1);
	else if (situation == (-3))
		ft_putstr_fd("2nd provided param to programm is not '--save':(\n", 1);
	else if (situation == (-100))
		ft_putstr_fd("Cant open file for screenshot :(\n", 1);
	else if (situation == (-101))
		ft_putstr_fd("Error occured when close file for screenshot:(\n", 1);
	else if (situation == 1)
		ft_putstr_fd("Error occured when open map config file\n", 1);
	else if (situation == 2)
		ft_putstr_fd("Error occured when close map config file\n", 1);
	else if (situation == 3)
		ft_putstr_fd("Map cant be separated by 1 or more empty line(s)\n", 1);
	else if (situation == 4)
		ft_putstr_fd("Incorrect char in map is found\n", 1);
	print_error_2(situation);
}

int		ft_exit(int status, t_vars *vars, int situation, int fd)
{
	if (fd > 0)
		close(fd);
	if (status == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", 1);
		print_error(situation);
	}
	if (vars)
		free_vars(vars);
	exit(status);
	return (status);
}
