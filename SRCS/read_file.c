/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:28:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 15:11:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_file(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	t_list	*garbage;

	garbage = ft_calloc(1, sizeof(t_list));
	map->height = get_height(file_name);
	map->width = get_width(file_name);
	map->z_matrix = ft_calloc(map->height, sizeof(int *));
	i = 0;
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (i < map->height)
	{
		map->z_matrix[i] = ft_calloc(map->width, sizeof(int));
		line = get_next_line(fd);
		fill_line(line, map->z_matrix[i]);
		i++;
	}
	collect_2int_garbage(map->z_matrix, garbage);
	dump_del(garbage);
}
