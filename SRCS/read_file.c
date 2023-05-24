/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:28:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 14:12:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(t_map *map, char *file_name)
{
	int		fd;
	char	*line;

	map->height = get_height(file_name);
	map->width = get_width(file_name);
	map->z_matrix = ft_calloc(data->height + 1, sizeof(int **));
}
