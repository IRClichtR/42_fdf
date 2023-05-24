/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:03:26 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 13:32:34 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
	{
		display_usage();
		return (0);
	}
	if (check_map(av[1]))
	{
		ft_putstr_fd("Error: Invalid Map\n");
		return (0);
	}
	map = ft_calloc(1, sizeof(t_map));
	read_file(map, av[1]);
	return (0);
}
