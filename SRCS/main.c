/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:03:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 16:45:26 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	(void)ac;
	t_map	*map;
/*
	if (ac != 2)
	{
		display_usage();
		return (0);
	}
	if (check_map(av[1]) == -1)
	{
		ft_putstr_fd("Error: Invalid Map\n", 2);
		return (0);
	}
*/
	map = ft_calloc(1, sizeof(t_map));
	read_file(map, av[1]);
	int	i = 0;
	int j = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%3d ", map->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free(map);
	return (0);
}
