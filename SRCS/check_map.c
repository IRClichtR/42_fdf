/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/26 13:02:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map(char *arg)
{
	int		fd;

	fd = open(arg, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd("Error with open(): check permissions or filename\n", 2);
		exit(127);
	}
	if (check_words(arg) == -1 || check_z(arg) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
