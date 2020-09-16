#include "cub3d.h"

/*
* param_name -> number
* NO -> 1
* SO -> 2
* WE -> 3
* EA -> 4
* S  -> 5
*/

int texture_param_parse(char *line, t_vars *vars, char *param_name, int param_nbr, int fd)
{
    int tmp;
    char *temp_ptr;

    // t_params *p;

    // p = vars->p;

    tmp = 0;
    // temp_ptr = NULL;
    if (param_nbr == 1)
        temp_ptr = vars->p->NO;
    else if (param_nbr == 2)
        temp_ptr = vars->p->SO;
    else if (param_nbr == 3)
        temp_ptr = vars->p->WE;
    else if (param_nbr == 4)
        temp_ptr = vars->p->EA;
    else if (param_nbr == 5)
        temp_ptr = vars->p->S;
    if (!temp_ptr)
    {  
        line += count_spaces_in_row(line);
        if ((param_nbr >= 1) && (param_nbr <= 4))
        {
            if ((*line++ != param_name[0]) || (*line++ != param_name[1]) || (*line++ != ' '))
			    ft_exit(EXIT_FAILURE, vars, 50, fd);
        }
        else if (param_nbr == 5)
        {
            if ((*line++ != param_name[0]) || (*line++ != ' '))
			    ft_exit(EXIT_FAILURE, vars, 50, fd);
        }
        line += count_spaces_in_row(line);
        while (line[tmp] && line[tmp] != ' ')
            tmp++;
        if (!(temp_ptr = ft_substr(line, 0, tmp)))
            ft_exit(EXIT_FAILURE, vars, -1, fd);
        line += tmp;
        line += count_spaces_in_row(line);
        if (*line)
            ft_exit(EXIT_FAILURE, vars, 52, fd);
        if (param_nbr == 1)
            vars->p->NO = temp_ptr;
        else if (param_nbr == 2)
            vars->p->SO = temp_ptr;
        else if (param_nbr == 3)
            vars->p->WE = temp_ptr;
        else if (param_nbr == 4)
            vars->p->EA = temp_ptr;
        else if (param_nbr == 5)
            vars->p->S = temp_ptr;
        return (0);
    }
    else
        ft_exit(EXIT_FAILURE, vars, 101, fd);
    return (0);
}


void r_param_parse_2(char *line, t_vars *vars, int fd)
{
    t_params *p;

    p = vars->p;
    if (p->r_height < 0)
        ft_exit(EXIT_FAILURE, vars, 51, fd);
    line += number_length(p->r_height);
    while (*line)
    {
        if (*line != ' ')
            ft_exit(EXIT_FAILURE, vars, 52, fd);
        line++;
    }
}

int r_param_parse(char *line, t_vars *vars, int fd)
{
    t_params *p;

    p = vars->p;
    if (!p->r_has_parsed)
    {  
        line += count_spaces_in_row(line);
        if ((*line++ != 'R') || (*line++ != ' '))
            ft_exit(EXIT_FAILURE, vars, 50, fd);
        line += count_spaces_in_row(line);
        p->r_width = ft_atoi(line);
        if (p->r_width < 0)
            ft_exit(EXIT_FAILURE, vars, 51, fd);
        line += number_length(p->r_width); 
        if (*line != ' ')
            ft_exit(EXIT_FAILURE, vars, 52, fd);
        line += count_spaces_in_row(line);
        p->r_height = ft_atoi(line);
        r_param_parse_2(line, vars, fd);
        p->r_has_parsed = 1;
    }
    else
        ft_exit(EXIT_FAILURE, vars, 101, fd);
    return (0);
}

int only_spaces_in_line(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}
int parse_params(t_vars *vars, int fd)
{
    char *line;

    line = vars->line;
    if (ft_strnstr(line, "R ", ft_strlen(line)))
        r_param_parse(line, vars, fd);
    else if (ft_strnstr(line, "NO ", ft_strlen(line)))
        texture_param_parse(line, vars, "NO", 1, fd);
    else if (ft_strnstr(line, "SO ", ft_strlen(line)))
        texture_param_parse(line, vars, "SO", 2, fd);
    else if (ft_strnstr(line, "WE ", ft_strlen(line)))
        texture_param_parse(line, vars, "WE", 3, fd);
    else if (ft_strnstr(line, "EA ", ft_strlen(line)))
        texture_param_parse(line, vars, "EA", 4, fd);
    else if (ft_strnstr(line, "S ", ft_strlen(line)))
        texture_param_parse(line, vars, "S", 5, fd);
    else if (ft_strnstr(line, "F ", ft_strlen(line)))
        rgb_param_parse(line, vars, 'F', fd);
    else if (ft_strnstr(line, "C ", ft_strlen(line)))
        rgb_param_parse(line, vars, 'C', fd);
    else if (!only_spaces_in_line(line))
        ft_exit(EXIT_FAILURE, vars, 50, fd);
    // printf("==%s\n", vars->line);
    // free(vars->line);
    // vars->line = NULL;
    return (0);
}