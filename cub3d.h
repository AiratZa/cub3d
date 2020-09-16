#include "./mlx_sources/minilibx_mms_20200219/mlx.h"
#include <stdio.h>
#include <math.h>
#include "parser/cub3d.h"
#include "./parser/cub3d.h"
#include <unistd.h>
# include "./includes/main.h"


//Mac OS
// #define KEY_UP_ARROW 126
// #define KEY_DOWN_ARROW 125
// #define KEY_LEFT_ARROW 123
// #define KEY_RIGHT_ARROW 124


// #define KEY_W 13
// #define KEY_A 0
// #define KEY_S 1 
// #define KEY_D 2

#define ESC_KEY 53

//Linux
#define KEY_UP_ARROW 65362
#define KEY_DOWN_ARROW 65364
#define KEY_LEFT_ARROW 65361
#define KEY_RIGHT_ARROW 65363


#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

//parameters for scaling and moving the sprites
#define uDiv 1
#define vDiv 1
#define vMove 0.0


// char *my_mlx_get_color(t_data *data, size_t x, size_t y);

void            my_mlx_pixel_put(t_data *data, size_t x, size_t y, int color);

int             close_window(t_vars *vars);

int		create_rgb(int r, int g, int b);

void draw_rectangle(t_data *img, const size_t img_w, const size_t img_h, const size_t x, const size_t y, const size_t w, const size_t h, int color);

int floor_and_ceiling(t_data **img, t_vars *vars, t_params *p);

int main_loop(t_vars *vars);

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);


int my_mlx_pixel_get(t_data *data, size_t x, size_t y);

int parse_sprites_pos_and_count(t_vars *vars);

t_sprites_pos *get_sprite_in_pos(t_sprites_pos *sprites, int pos);

int sprites_handler(t_vars *vars);

void quick_sort(int *order, double *distance, int count);


int get_textures(t_vars *vars);

void set_dir_n_plane(t_vars *vars, char player_dir);

void key_status_handler(t_vars *vars);

int             key_release_register(int keycode, t_vars *vars);

int             key_press_register(int keycode, t_vars *vars);

int create_new_image(t_vars *vars);

int				make_screenshot(t_vars *vars);

int             button_press_register(t_vars *vars);

void initial_check(int argc, char **argv, t_vars *vars);

void initial_param_set(t_vars *vars, t_data *img);

int initial_param_set_2(t_vars *vars, t_data *img);

void	init_keys(t_vars *vars);



int main_calculations(t_vars *vars);



void	ray_map_values(t_vars *vars);

void	step_size(t_draw *draw, t_vars *vars);

void	step_size_2(t_draw *draw, t_vars *vars);

void	calc_distance_n_side(t_draw *draw, t_vars *vars);

void	set_wall_side(t_draw *draw, t_vars *vars);



void dist_to_wall_n_start_end_wall(t_vars *vars);

void draw_floor_n_sky(t_vars *vars);

t_data *get_current_texture(t_vars *vars);

void draw_wall_line(t_vars *vars);

void	draw_line(t_vars *vars, double tex_pos, double step, int tex_x);
