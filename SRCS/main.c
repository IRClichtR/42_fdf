/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:03:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 11:49:47 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	display_usage(void)
{
	ft_printf("This program takes one argument : <filename>.\n");
	ft_printf("Make sure you have the reading rights and that the file is in");
	ft_printf(" the correct form\n");
}

int	main(int ac, char **av)
{
	t_map		*map;
	char		**all_lines;

	if (ac != 2)
	{
		display_usage();
		return (0);
	}
	all_lines = get_all_lines(av[1]);
	if (!all_lines)
		return (1);
	if (check_map(all_lines) == -1)
		return (1);
	map = ft_calloc(1, sizeof(t_map));
	read_file(map, all_lines);
	init_window(map);
	draw_all_lines(map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
