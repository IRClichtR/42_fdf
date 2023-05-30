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
	int		res;
	
	res = 0;
	fd = open(filename, O_RDONLY, 0);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == 0)
			break ;
		res = check_num(line);
		if (check_num(line) == -1)
			res = -1;
		free(line);
	}
	free(line);
	close(fd);
	if (res == -1)
		return (res);
	return (0);
}
