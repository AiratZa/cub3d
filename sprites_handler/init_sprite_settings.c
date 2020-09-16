/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:10 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:06:11 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				add_sprite_pos(int x, int y, t_vars *vars)
{
	t_sprites_pos *temp;

	temp = vars->sprites;
	while (temp->next)
		temp = temp->next;
	if (!(temp->next = malloc(sizeof(t_sprites_pos))))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	(temp->next)->x = x + 0.5;
	(temp->next)->y = y + 0.5;
	(temp->next)->next = NULL;
	return (0);
}

t_sprites_pos	*get_sprite_in_pos(t_sprites_pos *sprites, int pos)
{
	t_sprites_pos	*tmp;
	int				i;

	i = 0;
	tmp = sprites;
	while (i <= pos)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void			init_sprites(t_vars *vars)
{
	if (!(vars->sprites = malloc(sizeof(t_sprites_pos))))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	(vars->sprites)->x = -1;
	(vars->sprites)->y = -1;
	(vars->sprites)->next = NULL;
}

int				parse_sprites_pos_and_count(t_vars *vars)
{
	int				x;
	int				y;
	int				count;

	count = 0;
	y = 0;
	init_sprites(vars);
	while (y < vars->map_h)
	{
		x = 0;
		while (x < vars->map_w)
		{
			if ((vars->m_arr)[y][x] == '2')
			{
				add_sprite_pos(x, y, vars);
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}
