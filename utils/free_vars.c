/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:40:05 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:49:54 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_params(t_vars *vars)
{
	if (vars->p->no)
		free(vars->p->no);
	if ((vars->p)->so)
		free((vars->p)->so);
	if ((vars->p)->we)
		free((vars->p)->we);
	if ((vars->p)->ea)
		free((vars->p)->ea);
	if ((vars->p)->s)
		free((vars->p)->s);
	free(vars->p);
}

void	free_arr(t_vars *vars)
{
	int i;

	i = 0;
	while (i < (vars->map)->y_size)
	{
		if ((vars->m_arr)[i])
			free((vars->m_arr)[i]);
		i++;
	}
	free(vars->m_arr);
}

void	free_map(t_vars *vars)
{
	t_map_line *tmp;

	tmp = (vars->map)->start;
	while (tmp)
	{
		tmp = ((vars->map)->start)->next;
		free(((vars->map)->start)->line);
		free(((vars->map)->start));
		(vars->map)->start = tmp;
	}
	free(vars->map);
}

void	free_spr(t_vars *vars)
{
	t_sprites_pos *tmp;

	while (vars->sprites)
	{
		tmp = (vars->sprites);
		vars->sprites = tmp->next;
		free(tmp);
	}
}

void	free_vars(t_vars *vars)
{
	if (vars->m_arr)
		free_arr(vars);
	if (vars->line)
		free(vars->line);
	if (vars->p)
		free_params(vars);
	if (vars->map)
		free_map(vars);
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
