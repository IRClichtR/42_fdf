/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:02:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 12:00:18 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->img_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "FDF de Flo");
	mlx_hook(map->img_ptr, 2, 1L << 0, &press_key, map);
	mlx_hook(map->img_ptr, 17, 0, &close_window, map);
	map->zoom = 40;
}
