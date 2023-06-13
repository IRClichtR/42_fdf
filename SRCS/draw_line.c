/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/13 14:23:38 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	define_color(t_point *point, t_map *map)
{
//if z_matrix[y][x][z] !=0 color allready defined(!=0) return 
	if (point->z_dot < 0)
		map->color = 0x7fbfbf;/*bleu*/
	else if (point->z_dot >= 0 && point->z_dot <= 5)
		map->color = 0x7fbfbf;/*vert*/
	else if (point->z_dot > 5 && point->z_dot <= 15)
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

static void	define_point(t_vector *crd, t_point *point, t_map *map)
{
	point->x_dot = crd->x * map->zoom;
	point->y_dot = crd->y * map->zoom;
}

static void	define_z(t_point *point, t_map * map)
{
	point->z_dot = map->z_matrix[(int)point->y_dot][(int)point->x_dot];
	point->z1_dot = map->z_matrix[(int)point->y1_dot][(int)point->x1_dot];
}

void	draw_line(t_vector *crd, float x1, float y1, t_map *map)
{
	t_point	*point;

	point = ft_calloc(1, sizeof(t_point));
	define_point(crd, point, map);
	point->x1_dot = x1 * map->zoom;
	point->y1_dot = y1 * map->zoom;
	define_step(point);
	define_z(point, map);
	define_color(point, map);
	while ((int)(point->x_dot - point->x1_dot) != 0 
	|| (int)(point->y_dot - point->y1_dot) != 0)
	{
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, point->x_dot, point->y_dot, map->color);
printf("coucou\n");
		point->x_dot += point->dx;
		point->y_dot += point->dy;
	}
	free(point);
}
