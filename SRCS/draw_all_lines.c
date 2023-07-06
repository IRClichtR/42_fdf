/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bvector.y: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:23 bvector.y ftuernal          #+#    #+#             */
/*   Updated: 2023/07/06 15:13:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all_lines(t_map *map)
{
	t_vector	*vector;

	vector = ft_calloc(1, sizeof(t_vector));
	vector->y = 0;
	while (vector->y < map->height)
	{
		vector->x = 0;
		while (vector->x < map->width)
		{
			if (vector->x < map->width - 1)
				draw_line(vector, vector->x + 1, vector->y, map);
			if (vector->y < map->height - 1)
				draw_line(vector, vector->x, vector->y + 1, map);
			vector->x++;
		}
		vector->y++;
	}
	free(vector);
}
