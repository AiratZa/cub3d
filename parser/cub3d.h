#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include "../includes/main.h"




int map_parser(t_vars *vars, char *line, int fd);

int convert_map_to_rectangle(t_vars *vars);

// int map_params_parser(char *map_name, t_map *map, t_params *p);

// int map_params_parser(char *map_name, t_map **map, t_params **p);
void map_params_parser(char *map_name, t_vars *vars);


int check_map_borders(t_vars *vars);
void error_exit_with_message_incorrect_border_in_map(int x, int y);

// void error_exit_with_message(char *param_name, char *message);

void error_exit_with_message_incorrect_char_in_map(char c, int x, int y);

void error_exit_with_message_incorrect_border_in_map(int x, int y);

int rgb_param_parse(char *line, t_vars *vars, char param, int fd);

int parse_params(t_vars *vars, int fd);

int r_param_parse(char *line, t_vars *vars, int fd);

t_map_line	*ft_map_line_new(void *content);

t_map_line	*ft_map_line_last(t_map_line *lst);

void	ft_map_line_add_back(t_map_line **lst, t_map_line *new);

int count_spaces_in_row(char *line);

void    initial_params(t_vars *vars);
// void    initial_params(t_params *p);

int number_length(int nbr);

// TESTS

void test(t_map *map, t_params *p);

#endif
