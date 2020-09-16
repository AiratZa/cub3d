/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrake <gdrake@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 19:57:24 by gdrake            #+#    #+#             */
/*   Updated: 2020/09/10 20:00:37 by gdrake           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	swap(int pos1, int pos2, int *order, double *distance)
{
	int			tmp_order;
	double		tmp;

	tmp = distance[pos1];
	tmp_order = order[pos1];
	distance[pos1] = distance[pos2];
	distance[pos2] = tmp;
	order[pos1] = order[pos2];
	order[pos2] = tmp_order;
}

int		sort_part(int *order, double *distance, int left, int right)
{
	int			x;
	int			less;
	int			i;

	less = left;
	x = distance[right];
	i = left;
	while (i < right)
	{
		if (distance[i] >= x)
		{
			swap(i, less, order, distance);
			less++;
		}
		i++;
	}
	swap(less, right, order, distance);
	return (less);
}

void	quick_sort_recursion(int *order, double *distance, int left, int right)
{
	int			temp_border;

	if (left < right)
	{
		temp_border = sort_part(order, distance, left, right);
		quick_sort_recursion(order, distance, left, temp_border - 1);
		quick_sort_recursion(order, distance, temp_border + 1, right);
	}
}

void	quick_sort(int *order, double *distance, int count)
{
	if (count)
		quick_sort_recursion(order, distance, 0, count - 1);
}
