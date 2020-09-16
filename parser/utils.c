#include "cub3d.h"

int count_spaces_in_row(char *line)
{
    int i;

    i = 0;
    while(line[i] && (line[i] == ' '))
        i++;
    return (i);
}

void    initial_params(t_vars *vars)
{
    t_params *params;

    if (!(params = malloc(sizeof(t_params))))
        ft_exit(EXIT_FAILURE, vars, -1, 0);
    params->r_has_parsed = 0;
	params->r_width = 0;
	params->r_height = 0;
    params->NO = NULL;
    params->WE = NULL;
    params->EA = NULL;
    params->SO = NULL;
    params->S = NULL;
    params->f_rgb_has_parsed = 0;
    params->c_rgb_has_parsed = 0;
    vars->p = params;
}

int number_length(int nbr)
{
    int i;

    i = 1;
    if (nbr < 0)
    {
        i += 1;
        nbr *= -1;
    }
    while ((nbr / 10) != 0 )
    {
        nbr /= 10;
        i++;
    }
    return (i);
} 