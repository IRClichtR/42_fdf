/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:28:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 14:01:57 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_z(int **z_matrix, int size, int height)
{
	int	i;
	int	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < size)
		{
			printf("%d ", z_matrix[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	read_file(t_map *map, char **all_lines)
{
	int		i;

	map->height = get_height(all_lines);
	map->width = get_width(all_lines);
	map->z_matrix = ft_calloc(map->height, sizeof(int *));
	map->color_matrix = ft_calloc(map->height, sizeof(int *));
	i = 0;
	while (i < map->height)
	{
		map->z_matrix[i] = ft_calloc(map->width, sizeof(int));
		map->color_matrix[i] = ft_calloc(map->width, sizeof(int));
		fill_line(all_lines[i], map->z_matrix[i], map->color_matrix[i]);
		i++;
	}
printf("Z_MATRIX\n___\n");
print_z(map->z_matrix, map->width, map->height);
printf("COLOR_MATRIX\n___\n");
print_z(map->color_matrix, map->width, map->height);
	free(all_lines[i]);
	free(all_lines);
}
