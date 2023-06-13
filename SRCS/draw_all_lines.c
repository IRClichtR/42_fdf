/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/13 14:26:35 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_all_lines(t_map *map)
{
	t_vector	*crd;

	crd = ft_calloc(1, sizeof(t_vector));
	vector_init(crd);
	while (crd->y < map->height)
	{
		crd->x = 0;
		while (crd->x < map->width)
		{
			if (crd->x < map->width - 1)
				draw_line(crd, crd->x + 1, crd->y, map);
			if (crd->y < map->height - 1)
				draw_line(crd, crd->x, crd->y + 1, map);
			crd->x++;
		}
		printf("\n\n");
		crd->y++;
	}
	free(crd);
}
