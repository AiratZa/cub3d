/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:23:26 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:44:23 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include <stdlib.h>

typedef struct	s_params
{
	int		r_width;
	int		r_height;
	int		r_has_parsed;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f_rgb_has_parsed;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_rgb_has_parsed;
	int		c_r;
	int		c_g;
	int		c_b;

}				t_params;

typedef struct	s_map_line
{
	char				*line;
	int					x_size;
	struct s_map_line	*next;
}				t_map_line;

typedef struct	s_map
{
	t_map_line	*start;
	t_map_line	**arr_ptr;
	int			y_size;
	int			max_len_of_line;
	int			player_x_pos;
	int			player_y_pos;
	char		player_dir;
}				t_map;

typedef struct	s_data
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct	s_sprites_pos
{
	double					x;
	double					y;
	struct s_sprites_pos	*next;
}				t_sprites_pos;

typedef struct	s_tmp
{
	size_t	i;
	size_t	j;
}				t_tmp;

typedef struct	s_is_pressed
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_right_arrow;
	int	key_left_arrow;
}				t_is_pressed;

typedef struct	s_draw
{
	size_t	x;
	size_t	y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x_pos;
	int		map_y_pos;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	double	dist_to_wall;
	int		wall_height;
	int		draw_start;
	int		draw_end;
}				t_draw;

typedef struct	s_textures
{
	t_data	*text_n;
	t_data	*text_w;
	t_data	*text_e;
	t_data	*text_s;
	t_data	*text_sprite;
}				t_textures;

typedef struct	s_vars
{
	t_data			*img_data;
	t_params		*p;
	t_map			*map;
	t_textures		*textures;
	t_data			*current_texture;
	t_draw			*draw;
	t_is_pressed	*keys_status;
	t_sprites_pos	*sprites;
	char			**m_arr;
	int				map_h;
	int				map_w;
	int				win_w;
	int				win_h;
	void			*mlx_ptr;
	void			*win_ptr;
	float			player_angle;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	float			move_speed;
	float			rot_speed;
	float			plane_x;
	float			plane_y;
	char			w_side;
	int				sprites_count;
	double			*perp_lines;
	int				make_screenshot;
	char			*line;
	int				tmp;
	int				len;
	int				fd;
	int				i;
	int				j;
	char			*tmp_line;
}				t_vars;

typedef struct	s_s
{
	double	spritex;
	double	spritey;
	double	i_d;
	double	trans_x;
	double	trans_y;
	int		spritescreenx;
	int		vmovescreen;
	int		spriteheight;
	int		drawstarty;
	int		drawendy;
	int		spritewidth;
	int		drawstartx;
	int		drawendx;
}				t_s;

typedef struct	s_rgb
{
	int	*status;
	int	*r;
	int	*g;
	int	*b;
	int	fd;
}				t_rgb;
#endif
