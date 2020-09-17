/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:06:53 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 22:10:58 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include "../mlx_sources/minilibx_mms_20200219/mlx.h"
# include "../parser/map_parser.h"
# include "./structs.h"
# include "../libft/libft.h"

/*
** macOS
*/

# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC_KEY 53

/*
** Linux
** #define KEY_UP_ARROW 65362
** #define KEY_DOWN_ARROW 65364
** #define KEY_LEFT_ARROW 65361
** #define KEY_RIGHT_ARROW 65363
** #define KEY_W 119
** #define KEY_A 97
** #define KEY_S 115
** #define KEY_D 100
*/

/*
** Parameters for scaling and moving the sprites
*/

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

/*
** ENGINE DIR
*/

void			dist_to_wall_n_start_end_wall(t_vars *vars);

void			draw_floor_n_sky(t_vars *vars);

t_data			*get_current_texture(t_vars *vars);

void			draw_wall_line(t_vars *vars);

void			draw_line(t_vars *vars, double tex_pos,
							double step, int tex_x);

int				key_release_register(int keycode, t_vars *vars);

int				key_press_register(int keycode, t_vars *vars);

int				button_press_register(t_vars *vars);

void			arrow_keys_handler(t_vars *vars);

void			w_s_keys_handler(t_vars *vars);

void			a_key_handler(t_vars *vars);

void			a_d_keys_handler(t_vars *vars);

void			key_status_handler(t_vars *vars);

void			ray_map_values(t_vars *vars);

void			step_size(t_draw *draw, t_vars *vars);

void			step_size_2(t_draw *draw, t_vars *vars);

void			calc_distance_n_side(t_draw *draw, t_vars *vars);

void			set_wall_side(t_draw *draw, t_vars *vars);

void			init_perp_lines(t_vars *vars);

int				main_calculations(t_vars *vars);

int				main_loop(t_vars *vars);

int				make_screenshot(t_vars *vars);

void			fill_header_spec(unsigned char *file_header, \
unsigned char *info_header, t_vars *vars);

void			write_bmp_info(unsigned char *file_header,\
unsigned char *info_header, t_vars *vars, char *file_name);

/*
** SPRITES_HANDLER DIR
*/

int				parse_sprites_pos_and_count(t_vars *vars);

void			init_sprites(t_vars *vars);

t_sprites_pos	*get_sprite_in_pos(t_sprites_pos *sprites, int pos);

int				add_sprite_pos(int x, int y, t_vars *vars);

int				sprites_handler(t_vars *vars);

void			draw_sprite(t_vars *vars, int i, int *order);

void			set_start_end_x_y(t_vars *vars, t_s *s);

void			draw_sprite_stripe(t_vars *vars, t_s *s, int stripe);

/*
** UTILS DIR
*/

int				clear_imgs_n_close_window(t_vars *vars);

void			clear_txts(t_vars *vars);

void			clear_txts_2(t_vars *vars);

void			free_vars(t_vars *vars);

void			free_spr(t_vars *vars);

void			free_map(t_vars *vars);

void			free_arr(t_vars *vars);

void			free_params(t_vars *vars);

int				ft_exit(int status, t_vars *vars, int situation, int fd);

void			print_error(int situation);

void			print_error_2(int situation);

int				create_new_image(t_vars *vars);

int				create_rgb(int r, int g, int b);

int				my_mlx_pixel_get(t_data *data, size_t x, size_t y);

void			my_mlx_pixel_put(t_data *data, size_t x, size_t y, int color);

int				initial_param_set_2(t_vars *vars, t_data *img);

void			set_dir_n_plane(t_vars *vars, char player_dir);

void			set_dir_n_plane_2(t_vars *vars, char player_dir);

void			set_initial_player_pos_n_speed(t_vars *vars);

void			configure_screen_size(void *mlx_ptr, int *x, int *y);

void			initial_param_set(t_vars *vars, t_data *img);

void			init_keys(t_vars *vars);

void			initial_check(int argc, char **argv, t_vars *vars);

int				get_textures(t_vars *vars);

int				load_texture(char *file_name, t_vars *vars, char side);

void			init_textures(t_vars *vars);

void			exit_txt(t_vars *vars, t_data *txt);

void			quick_sort(int *order, double *distance, int count);

int				sort_part(int *order, double *distance, int left, int right);

void			swap(int pos1, int pos2, int *order, double *distance);

/*
** GET_NEXT_LINE DIR HAS OWN HEADER FILE
*/

/*
** LIBFT DIR HAS OWN HEADER FILE
*/

/*
** PARSER DIR HAS OWN HEADER FILE
*/

/*
** CORE DIR
*/

void			init_vars_img(t_vars *vars, t_data *img);

#endif
