#include "cub3d.h"

int rgb_param_parse(char *line, t_vars *vars, char param, int fd)
{
    int *tmp_status;

    int *tmp_r;
    int *tmp_g;
    int *tmp_b;

    t_params *p;
    p = vars->p;
    tmp_status = NULL;
    if (param == 'C')
    {
        tmp_status = &(p->c_rgb_has_parsed);
        tmp_r = &(p->c_r);
        tmp_g = &(p->c_g);
        tmp_b = &(p->c_b);
    }
    else if (param == 'F')
    {
        tmp_status = &(p->f_rgb_has_parsed);
        tmp_r = &(p->f_r);
        tmp_g = &(p->f_g);
        tmp_b = &(p->f_b);
    }
    if (!*tmp_status)
    {  
        line += count_spaces_in_row(line);
        if ((*line++ != param) || (*line++ != ' '))
            ft_exit(EXIT_FAILURE, vars, 50, fd);
        line += count_spaces_in_row(line);
        *tmp_r = ft_atoi(line);
        if ((*tmp_r) < 0)
            ft_exit(EXIT_FAILURE, vars, 51, fd);
        line += number_length(*tmp_r);
        line += count_spaces_in_row(line);
        if (*line != ',')
            ft_exit(EXIT_FAILURE, vars, 500, fd);
        else
            line++;
        line += count_spaces_in_row(line);
        *tmp_g = ft_atoi(line);
        if ((*tmp_g) < 0)
            ft_exit(EXIT_FAILURE, vars, 51, fd);
        line += number_length(*tmp_g);
        line += count_spaces_in_row(line);
        if (*line != ',')
            ft_exit(EXIT_FAILURE, vars, 500, fd);
        else
            line++;
        line += count_spaces_in_row(line);
        *tmp_b = ft_atoi(line);
        if ((*tmp_b) < 0)
            ft_exit(EXIT_FAILURE, vars, 51, fd);
        line += number_length(*tmp_b);
        line += count_spaces_in_row(line);
        if (*line != '\0')
            ft_exit(EXIT_FAILURE, vars, 501, fd);
        *tmp_status = 1;
    }
    else
        ft_exit(EXIT_FAILURE, vars, 101, fd);
    return (0);
}