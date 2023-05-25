/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 12:47:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_vector *crd, t_map *map)
{
	float	dx;
	float	dy;
	int		*max;

	dx = crd->x1 - crd->x;
	dy = crd->y1 - crd->y;
	max = define_max(define_absvalue(dx), define_absvalue(dy));
	dx /= *max;
	dy /= *max;
	while ((crd->x - crd->x1) || (crd->y - crd->y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, crd->x, crd->y, 0xffffff);
		crd->x += dx;
		crd->y += dy;
	}
}
