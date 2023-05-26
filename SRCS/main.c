/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:03:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 14:24:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	display_usage(void)
{
	ft_printf("This program takes one argument : <filename>.\n");
	ft_printf("Make sure you have the reading rights and that the file is in");
	ft_printf("the correct form\n");
}

int	main(int ac, char **av)
{
//	(void)ac;
	t_map		*map;
	t_vector	*crd;

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
	map = ft_calloc(1, sizeof(t_map));
	read_file(map, av[1]);
	crd = ft_calloc(1, sizeof(t_vector));
	vector_init(crd);

//TEST DISPLAY A LINE ON MAP
	init_window(map);
		
/*TEST READ_MAP
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
*/
	mlx_loop(map->mlx_ptr);
	return (0);
}
