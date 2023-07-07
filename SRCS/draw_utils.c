/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:23:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 11:59:40 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_point(t_vector *crd, float x1, float y1, t_point *point)
{
	point->x_dot = crd->x;
	point->y_dot = crd->y;
	point->x1_dot = x1;
	point->y1_dot = y1;
}

void	define_z(t_point *point, t_map *map)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	x = point->x_dot;
	y = point->y_dot;
	x1 = point->x1_dot;
	y1 = point->y1_dot;
	point->z_dot = map->z_matrix[(int)y][(int)x];
	point->z1_dot = map->z_matrix[(int)y1][(int)x1];
}

void	define_zoom(t_point *point, t_map *map)
{
	point->x_dot *= map->zoom;
	point->y_dot *= map->zoom;
	point->x1_dot *= map->zoom;
	point->y1_dot *= map->zoom;
}

void	define_step(t_point *point)
{
	point->dx = point->x1_dot - point->x_dot;
	point->dy = point->y1_dot - point->y_dot;
	point->max = define_max(point->dx, point->dy);
	point->dx /= point->max;
	point->dy /= point->max;
}

void	define_shift(t_point *point)
{
	point->x_dot += 360;
	point->y_dot += 360;
	point->x1_dot += 360;
	point->y1_dot += 360;
}
