/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:20:00 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 11:04:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_z(char *filename)
{
	int		fd;
	char	*line;
	
	fd = open(filename, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		if (check_num(line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	return (0);
}
