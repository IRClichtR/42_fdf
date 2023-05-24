/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 13:26:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char *arg)
{
	int		fd;
	t_map	*map;

	fd = open(argument, O_RDONLY, 0);
	if (check_words() == -1 || check_z() == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
