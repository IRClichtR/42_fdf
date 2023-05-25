/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 10:24:59 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char *arg)
{
	int		fd;
	t_map	*map;

	fd = open(argument, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd("Error with open(): check permissions or filename\n");
		exit(127);
	}
	if (check_words() == -1 || check_z() == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
