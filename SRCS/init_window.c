/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:02:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/29 14:25:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_window(t_map *map)
{
	void	*ptr;

	ptr = &press_key;
	map->mlx_ptr = mlx_init();
	map->img_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "FDF de Floriane");
	mlx_key_hook(map->img_ptr, ptr, &map->mlx_ptr);
	mlx_hook(map->img_ptr, 17, 0, &close_window, map);
	map->zoom = 50;
}
