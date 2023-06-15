/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:14:58 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/15 18:11:23 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	press_key(int keycode, t_map *map)
{
//printf("map ? == %p\n", map);
//printf("map->z_matrix ? == %p\n", map->z_matrix);
	if (keycode == 65307)
	{
		printf("before close\n");
		close_window(map);
		printf("after close\n");
	}
	return (0);
}
