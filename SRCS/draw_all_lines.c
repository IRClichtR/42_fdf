/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:54:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/29 11:38:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_point(t_point *p1, t_point *p2)
{
	p1->x = (j - i) * 30 + WIDTH / 2;
	p1->y = (i + j) * 15 + HEIGHT / 2 - matrix[i][j];
	p1->z = matrix[i][j];
	p2->x = (j - (i + 1)) * 30 + WIDTH / 2;
	p2->y = (j + (i + 1)) * 15 + HEIGHT / 2;
	p2->z = matrix[i + 1][j];
	draw_line(map, p1, p2);
}

void	draw_all_lines(t_map *map)
{
	t_point	*p1;
	t_point	*p2;
	int		i;
	int		j;

	i = 0;
	p1 = ft_calloc(1, sizeof(t_point));
	p2 = ft_calloc(1, sizeof(t_point));
	while (i < map->width - 1)
	{
		j = 0;
		while (j < map->height)
		{
			if (i < map->width - 1)
				draw_point(map, p1, p2);
			if (j < map->height - 1)
				draw_point(map, p1, p2);
			j++;
		}
		i++;
	}
	free(p1);
	free(p2);
}
























































































/*
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
		crd->y++;
	}
	free(crd);
}
*/
