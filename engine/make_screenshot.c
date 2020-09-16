/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_screenshot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:52 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:06:53 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_header_spec(unsigned char *file_header, \
unsigned char *info_header, t_vars *vars)
{
	int file_size;

	file_size = 14 + 40 + vars->win_w * vars->win_h * \
			(vars->img_data)->bits_per_pixel / 8;
	file_header[0] = 'B';
	file_header[1] = 'M';
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(vars->win_w);
	info_header[5] = (unsigned char)(vars->win_w >> 8);
	info_header[6] = (unsigned char)(vars->win_w >> 16);
	info_header[7] = (unsigned char)(vars->win_w >> 24);
	info_header[8] = (unsigned char)(-vars->win_h);
	info_header[9] = (unsigned char)(-vars->win_h >> 8);
	info_header[10] = (unsigned char)(-vars->win_h >> 16);
	info_header[11] = (unsigned char)(-vars->win_h >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)((vars->img_data)->bits_per_pixel);
}

void	write_bmp_info(unsigned char *file_header,\
unsigned char *info_header, t_vars *vars, char *file_name)
{
	int		fd;
	int		line_len;
	int		i;

	i = 0;
	if ((fd = open(file_name, O_RDWR | O_CREAT, 0755)) < 0)
		ft_exit(EXIT_FAILURE, vars, -100, 0);
	write(fd, file_header, 14);
	write(fd, info_header, 40);
	line_len = (vars->img_data)->bits_per_pixel / 8 * vars->win_w;
	while (i < vars->win_h)
	{
		write(fd, (vars->img_data)->addr + i *\
			(vars->img_data)->size_line, line_len);
		i++;
	}
	if (close(fd) != 0)
		ft_exit(EXIT_FAILURE, vars, -101, 0);
}

int			make_screenshot(t_vars *vars)
{
	unsigned char file_header[14];
	unsigned char info_header[40];

	ft_bzero(file_header, 14);
	ft_bzero(info_header, 40);
	fill_header_spec(file_header, info_header, vars);
	write_bmp_info(file_header, info_header, vars, "screenshot.bmp");
	return (0);
}
