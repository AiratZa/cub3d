/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:36:17 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/18 18:40:52 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../includes/structs.h"
# include "../includes/cub3d.h"
# include <stdio.h>

int			check_max_len_line(t_map *map);

void		malloc_arr(t_vars *vars);

void		ft_copy_line(t_vars *vars, t_map_line *tmp_line);

void		ft_resize_line(t_vars *vars, t_map_line *tmp_line);

int			convert_map_to_rectangle(t_vars *vars);

void		map_params_parser(char *map_name, t_vars *vars);

int			check_to_top(int x, int y, t_vars *vars);

int			check_to_bot(int x, int y, t_vars *vars);

int			check_to_left(int x, int y, t_vars *vars);

int			check_to_right(int x, int y, t_vars *vars);

int			check_map_borders(t_vars *vars);

void		map_parser_2(t_vars *vars);

void		get_new_line(t_vars *vars, char *line, int fd, int *inc);

int			init_map(t_vars *vars);

int			map_parser(t_vars *vars, char *line, int fd);

void		map_line_len_append_and_check(t_vars *vars);

void		check_chars_and_entry_point_2(t_vars *vars,
										char tmp_char, int *found);

void		check_chars_and_entry_point(t_vars *vars);

int			parse_params(t_vars *vars, int fd);

int			r_param_parse(char *line, t_vars *vars, int fd);

void		r_param_parse_2(char *line, t_vars *vars, int fd);

int			rgb_param_parse(char *line, t_vars *vars, char param, int fd);

void		rgb_param_parse_2(char *line, t_vars *vars, char param, t_rgb *tmp);

void		rgb_param_parse_3(char *line, t_vars *vars, char param, t_rgb *tmp);

t_map_line	*ft_map_line_new(void *content);

t_map_line	*ft_map_line_last(t_map_line *lst);

void		ft_map_line_add_back(t_map_line **lst, t_map_line *new);

int			texture_param_parse(char *line, t_vars *vars,
								char *param_name, int param_nbr);

void		texture_param_parse2(char *line, t_vars *vars,
								int param_nbr, char *temp_ptr);

void		put_in_struct(t_vars *vars, int param_nbr, char *temp_ptr);

int			count_spaces_in_row(char *line);

void		initial_params(t_vars *vars);

int			number_length(int nbr);

int			only_spaces_in_line(char *line);

int			ft_strlen_sym(char *str);

#endif
