/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/11 10:31:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_vector *crd, float x1, float y1, t_map *map)
{
	t_point		*pt;

	pt = ft_calloc(1, sizeof(t_point));
	define_point(crd, x1, y1, pt);
	define_z(pt, map);
	define_color(pt, map);
	define_zoom(pt, map);
	define_isometric(&pt->x_dot, &pt->y_dot, pt->z_dot);
	define_isometric(&pt->x1_dot, &pt->y1_dot, pt->z1_dot);
	define_shift(pt);
	define_step(pt);
	while ((int)(pt->x_dot - pt->x1_dot) != 0
	|| (int)(pt->y_dot - pt->y1_dot) != 0)
	{
		mlx_pixel_put(map->mlx_ptr, map->img_ptr, pt->x_dot, pt->y_dot, \
			map->color);
		pt->x_dot += pt->dx;
		pt->y_dot += pt->dy;
		if (pt->x_dot >= WIDTH || pt->x1_dot >= WIDTH
			|| pt->y_dot >= HEIGHT || pt->y1_dot >= HEIGHT)
			break ;
	}
	free(pt);
}
