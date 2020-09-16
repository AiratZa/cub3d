#include "cub3d.h"

void map_struct_to_array(t_vars *vars)
{
	t_map_line *tmp;
	int i;

	i = 0;
	if (!((vars->map)->arr_ptr = malloc(sizeof(t_map_line *) * (vars->map)->y_size)))
		ft_exit(EXIT_FAILURE, vars, -1, 0);
	tmp = (vars->map)->start;
	while (i < (vars->map)->y_size)
	{
		((vars->map)->arr_ptr)[i] = tmp;
		i++;
		tmp = tmp->next;
	}
}

int	ft_strlen_sym(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] != ' ')
			j++;
		i++;
	}
	return (j);
}
/*
* Except for the map content, each type of element can be separated by one or
* more empty line(s)
*/

void    map_line_len_append_and_check(t_vars *vars)
{
	int i;
	int count_empty_lines;
	int len;

	i = 0;
	count_empty_lines = 0;
	len = 0;
	while (i < (vars->map)->y_size)
	{
		len = ft_strlen_sym((vars->m_arr)[i]);
		if (len && count_empty_lines)
			ft_exit(EXIT_FAILURE, vars, 3, 0);
		if (!len)
			count_empty_lines++;
		i++;
	}
}

void check_chars_and_entry_point_2(t_vars *vars, char tmp_char, int *found, int i, int j)
{
	if ((tmp_char != ' ') && (tmp_char != '0') && (tmp_char != '1') && 
	(tmp_char != '2') && (tmp_char != 'N') && (tmp_char != 'S') &&  
	(tmp_char != 'E') && (tmp_char != 'W'))
		ft_exit(EXIT_FAILURE, vars, 4, 0);
	if ((tmp_char == 'N') || (tmp_char == 'S') ||\
	(tmp_char == 'E') || (tmp_char == 'W'))
	{
		if (*found)
			ft_exit(EXIT_FAILURE, vars, 400, 0);
		else
		{
			(vars->m_arr)[i][j] = '0';
			(vars->map)->player_x_pos = j;
			(vars->map)->player_y_pos = i;
			(vars->map)->player_dir = tmp_char;
			(*found) = 1;
		}
	}
}

void check_chars_and_entry_point(t_vars *vars)
{
	int i;
	int j;
	char tmp_char;
	int found;

	i = 0;
	found = 0;
	while (i < (vars->map)->y_size)
	{
		j = 0;
		while((vars->m_arr)[i][j] && (tmp_char = (vars->m_arr)[i][j]))
		{
			check_chars_and_entry_point_2(vars, tmp_char, &found, i, j);
			j++;
		}
		i++;
	}
	if (!found)
		ft_exit(EXIT_FAILURE, vars, 401, 0);
}

void testing(char **arr, t_vars *vars)
{
	int i;
	int j;

	i = 0;

	printf("R %d %d\n", (vars->p)->r_width, (vars->p)->r_height);
	printf("NO %s\n", (vars->p)->NO);
	printf("SO %s\n", (vars->p)->SO);
	printf("WE %s\n", (vars->p)->WE);
	printf("EA %s\n", (vars->p)->EA);
	printf("S %s\n", (vars->p)->S);
	printf("F %d, %d, %d\n", vars->p->f_r, vars->p->f_g, vars->p->f_b);
	printf("C %d, %d, %d\n", vars->p->c_r, vars->p->c_g, vars->p->c_b);
	while (i < (vars->map)->y_size)
	{
		ft_putstr_fd("|", 1);
		ft_putstr_fd(arr[i], 1);
		ft_putstr_fd("|\n", 1);
		i++;
	}
}

int map_parser_2(t_vars *vars)
{
	convert_map_to_rectangle(vars);
	check_chars_and_entry_point(vars);
	map_line_len_append_and_check(vars);
	check_map_borders(vars);
	testing(vars->m_arr, vars);
}


void get_new_line(t_vars *vars, char *line, int fd, int *inc)
{
	t_map_line  *tmp;

	if (!(tmp = ft_map_line_new(line)))
		ft_exit(EXIT_FAILURE, vars, -1, fd);
	ft_map_line_add_back(&((vars->map)->start), tmp);
	(*inc)++;
}

int	init_map(t_vars *vars)
{
	if (!(vars->map = malloc(sizeof(t_map))))
		return (-1);
	(vars->map)->start = NULL;
    (vars->map)->arr_ptr = NULL;
	return (0);
}

int map_parser(t_vars *vars, char *line, int fd)
{
	int i;


	i = 0;
	if (init_map(vars) == (-1))
		ft_exit(EXIT_FAILURE, vars, -1, fd);
	while ((get_next_line(fd, &(vars->line))) > 0 && (ft_strlen(vars->line) == 0))
	{
		free(vars->line);
		vars->line = NULL;
	}
	if (vars->line)
	{
		if (!((vars->map)->start = ft_map_line_new(vars->line)))
			ft_exit(EXIT_FAILURE, vars, -1, fd);
		i++;
		while ((get_next_line(fd, &(vars->line))) > 0)
			get_new_line(vars, vars->line, fd, &i);
	}
	(vars->map)->y_size = i;
	if (close(fd))
        ft_exit(EXIT_FAILURE, vars, 2, 0); 
	map_parser_2(vars);
	return (0);
}
