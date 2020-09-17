/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:29:45 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/17 21:48:31 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/map_parser.h"

void testing(char **arr, t_vars *vars)
{
	int i;
	int j;

	i = 0;

	printf("R %d %d\n", (vars->p)->r_width, (vars->p)->r_height);
	printf("NO %s\n", (vars->p)->no);
	printf("SO %s\n", (vars->p)->so);
	printf("WE %s\n", (vars->p)->we);
	printf("EA %s\n", (vars->p)->ea);
	printf("S %s\n", (vars->p)->s);
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