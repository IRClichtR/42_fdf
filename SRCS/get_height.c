/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:36:58 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 14:08:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	count = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == 0)
			break;
		free(line);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}
