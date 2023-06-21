/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:42:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 17:14:59 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	delete_matrix(t_map* map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->z_matrix[i]);
		free(map->color_matrix[i]);
		i++;
	}
	free(map->z_matrix);
	free(map->color_matrix);
}

int	close_window(t_map *map)
{
	delete_matrix(map);
	mlx_clear_window(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->img_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	free(map);
	exit(0);
	return (0);
}
