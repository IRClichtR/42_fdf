/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/13 19:26:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	define_color(t_point *point, t_map *map)
{
//if z_matrix[y][x][z] !=0 color allready defined(!=0) return 
	if (point->z_dot < 0)
		map->color = 0x7fbfbf;/*bleu*/
	else if (point->z_dot == 0)
		map->color = 0x7fbfbf;/*vert*/
	else if (point->z_dot >= 1 && point->z_dot <= 15)
		map->color = 0x7fbf7f;/*vert fonce*/
	else if (point->z_dot > 15 && point->z_dot <= 25)
		map->color = 0xd6a36e;/*marron clair*/
	else
		map->color = 0xa18c76;/*marron fonce*/
}

static void	define_step(t_point *point)
{
	point->dx = point->x1_dot - point->x_dot;
	point->dy = point->y1_dot - point->y_dot;
	point->max = define_max(point->dx, point->dy);
	point->dx /= point->max;
	point->dy /= point->max;
}

static void	define_point(t_vector *crd, int x1, int y1, t_point *point)
{
	point->x_dot = crd->x;
	point->y_dot = crd->y;
	point->x1_dot = x1;
	point->y1_dot = y1;
}

static void	define_z(t_point *point, t_map *map)
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

static void	define_zoom(t_point *point, t_map * map)
{
	point->x_dot *= map->zoom;
	point->y_dot *= map->zoom;
	point->x1_dot *= map->zoom;
	point->y1_dot *= map->zoom;
}

void	draw_line(t_vector *crd, float x1, float y1, t_map *map)
{
	t_point		*point;

	point = ft_calloc(1, sizeof(t_point));

	define_point(crd, x1, y1, point);
	define_z(point, map);
	define_zoom(point, map);
	make_topo(point);
	define_step(point);
	define_color(point, map);
	while ((int)(point->x_dot - point->x1_dot) != 0 
	|| (int)(point->y_dot - point->y1_dot) != 0)
	{
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, point->x_dot, point->y_dot, map->color);
		point->x_dot += point->dx;
		point->y_dot += point->dy;
	}
	free(point);
}
