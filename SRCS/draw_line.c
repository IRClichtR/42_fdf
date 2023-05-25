/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:37:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 12:43:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_vector *coord, t_map *map)
{
	float	dx;
	float	dy;
	int		*max;

	dx = coord->x1 - coord->x;
	dy = coord->y1 - coord->y;
	max = define_max(define_absvalue(dx), define_absvalue(dy));
	dx /= *max;
	dy /= *max;
	while ((coord->x - coord->x1) || (coord->y - coord->y1))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, coord->x, coord->y, 0xffffff);
		coord->x += dx;
		coord->y += dy;
	}
}
