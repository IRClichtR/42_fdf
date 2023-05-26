/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:42:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 14:26:07 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_map *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_ptr);
	mlx_clear_window(map->mlx_ptr, map->img_ptr);
	mlx_destroy_window(map->mlx_ptr, map->img_ptr);
	mlx_destroy_display(map->mlx_ptr);
	exit(0);
	return (0);
}
