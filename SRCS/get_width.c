/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:07:49 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/24 14:07:51 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		count;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	count = 1;
	while (line != 0)
	{
		if (line[i] == ' ')
			count += 1;
		i++;
	}
	free(line);
	close(fd);
	return (count);
}
