/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/31 14:27:01 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_words(char *filename)
{
	int		width;
	int		fd;
	char	*line;
	int		i;
	int		res;

	fd = open(filename, O_RDONLY, 0);
	width = get_width(filename);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == 0)
			break ;
		i = word_count(line, ' ');
		if (i != width)
			res = -1;
		free(line);
	}
//	free(line);
	close(fd);
	if (res == -1)
		return (res);
	return (0);
}
