/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handler_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 20:06:12 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:06:13 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_sprite_stripe(t_vars *vars, t_s *s, int stripe)
{
	int tex_x;
	int tex_y;
	int y;
	int clr;
	int d;

	tex_x = (int)(256 * (stripe - (-s->spriteWidth / 2 + s->spriteScreenX)) *\
			vars->textures->text_sprite->width / s->spriteWidth) / 256;
	if ((s->trans_y > 0) && (stripe > 0) &&\
		(stripe < vars->win_w) && (s->trans_y < (vars->perp_lines)[stripe]))
	{
		y = s->drawStartY;
		while (y < s->drawEndY)
		{
			d = (y - s->vMoveScreen) * 256 - vars->win_h * 128 +\
				s->spriteHeight * 128;
			tex_y = ((d * vars->textures->text_sprite->height) /\
						s->spriteHeight) / 256;
			clr = my_mlx_pixel_get(vars->textures->text_sprite, tex_x, tex_y);
			if (clr > 0)
				my_mlx_pixel_put(vars->img_data, stripe, y, clr);
			y++;
		}
	}
}

void	set_start_end_x_y(t_vars *vars, t_s *s)
{
	if (s->drawStartY < 0)
		s->drawStartY = 0;
	s->drawEndY = s->spriteHeight / 2 + vars->win_h / 2 + s->vMoveScreen;
	if (s->drawEndY >= vars->win_h)
		s->drawEndY = vars->win_h - 1;
	s->spriteWidth = abs((int)(vars->win_h / (s->trans_y))) / uDiv;
	s->drawStartX = -s->spriteWidth / 2 + s->spriteScreenX;
	if (s->drawStartX < 0)
		s->drawStartX = 0;
	s->drawEndX = s->spriteWidth / 2 + s->spriteScreenX;
	if (s->drawEndX >= (vars->win_w))
		s->drawEndX = vars->win_w - 1;
}

void	draw_sprite(t_vars *vars, int i, int *order)
{
	t_s				s;
	t_sprites_pos	*tmp_sprite;
	int				stripe;

	tmp_sprite = get_sprite_in_pos(vars->sprites, order[i]);
	s.spriteX = tmp_sprite->x - vars->pos_x;
	s.spriteY = tmp_sprite->y - vars->pos_y;
	s.i_d = 1.0 / (vars->plane_x * vars->dir_y - vars->dir_x * vars->plane_y);
	s.trans_x = s.i_d * (vars->dir_y * s.spriteX - vars->dir_x * s.spriteY);
	s.trans_y = s.i_d * (-1.0 * (vars->plane_y) * s.spriteX +\
				vars->plane_x * s.spriteY);
	s.spriteScreenX = (int)((vars->win_w / 2) * (1 + s.trans_x / s.trans_y));
	s.vMoveScreen = (int)(vMove / s.trans_y);
	s.spriteHeight = abs((int)(vars->win_h / (s.trans_y))) / vDiv;
	s.drawStartY = -s.spriteHeight / 2 + vars->win_h / 2 + s.vMoveScreen;
	set_start_end_x_y(vars, &s);
	stripe = s.drawStartX;
	while (stripe < s.drawEndX)
	{
		draw_sprite_stripe(vars, &s, stripe);
		stripe++;
	}
}

int		sprites_handler(t_vars *vars)
{
	int				sprite_order[vars->sprites_count];
	double			sprite_distance[vars->sprites_count];
	int				i;
	t_sprites_pos	*tmp_sprite;

	i = 0;
	while (i < vars->sprites_count)
	{
		tmp_sprite = get_sprite_in_pos(vars->sprites, i);
		sprite_order[i] = i;
		sprite_distance[i] = pow((vars->pos_x - tmp_sprite->x), 2) +\
								pow((vars->pos_y - tmp_sprite->y), 2);
		i++;
	}
	quick_sort(sprite_order, sprite_distance, vars->sprites_count);
	i = 0;
	while (i < vars->sprites_count)
	{
		draw_sprite(vars, i, &(sprite_order[0]));
		i++;
	}
	return (0);
}
