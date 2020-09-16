#include "cub3d.h"

int check_max_len_line(t_map *map)
{
	int i;
	int tmp;
	int max;
	t_map_line *tmp2;

	i = 0;
	tmp = 0;
	max = 0;
	tmp2 = map->start;
	while (i < map->y_size)
	{
		tmp = ft_strlen(tmp2->line);
		if (tmp > max)
			max = tmp;
		tmp2 = tmp2->next;
		i++;
	}
	return (max);
}

int convert_map_to_rectangle(t_vars *vars)
{
	int i;
	int tmp;
	t_map_line *tmp2;

	char **arr;
	int j;

	int k;

	i = 0;
	tmp = 0;

	(vars->map)->max_len_of_line = check_max_len_line(vars->map);
	arr = malloc(sizeof(char *) * (vars->map)->y_size);
	while (i < (vars->map)->y_size)
	{
		arr[i] = malloc(sizeof(char) * ((vars->map)->max_len_of_line + 1));
		i++;
	}
	i = 0;

	tmp2 = (vars->map)->start;
	while (i < (vars->map)->y_size)
	{
		j = 0;

		tmp = ft_strlen((tmp2->line));
		if (tmp < (vars->map)->max_len_of_line)
		{
			while (j < tmp)
			{
				arr[i][j] = (tmp2->line)[j];
				j++;
			}
			while (j < ((vars->map)->max_len_of_line))
			{
				arr[i][j] = ' ';
				j++;
			}
			arr[i][j] = '\0';
		}
		else
		{
			while (j < (vars->map)->max_len_of_line)
			{
				arr[i][j] = (tmp2->line)[j];
				j++;
			}
			arr[i][j] = '\0';
		}
		
		i++;
		tmp2 = tmp2->next;
	}
	vars->m_arr = arr;
	return (0);
}

void map_params_parser(char *map_name, t_vars *vars)
{
	int         fd;
	int         only_map_left;

	only_map_left = 0;
	initial_params(vars);
	if ((fd = open(map_name, O_RDONLY)) < 0)
		ft_exit(EXIT_FAILURE, vars, 1, 0);
	while (!only_map_left && (get_next_line(fd, &(vars->line))))
	{
		parse_params(vars, fd);
		if ((vars->p)->r_has_parsed && (vars->p)->NO && (vars->p)->WE && (vars->p)->EA\
			&& (vars->p)->SO && (vars->p)->S && (vars->p)->f_rgb_has_parsed \
			&& (vars->p)->c_rgb_has_parsed)
			only_map_left = 1;
		free(vars->line);
		vars->line = NULL;
	}
	map_parser(vars, vars->line, fd);
}
