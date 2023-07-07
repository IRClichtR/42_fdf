/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:30:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 11:32:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_color(t_point *pt, t_map *map)
{
	if (map->color_matrix[(int)pt->y_dot][(int)pt->x_dot] > 0)
		map->color = map->color_matrix[(int)pt->y_dot][(int)pt->x_dot];
	else
	{
		if (pt->z_dot <= 0)
			map->color = 0xffffff;
		else
			map->color = 0xff33f3;
	}
}

void	define_isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.816);
	*y = (*x + *y) * sin(0.816) - z;
}
