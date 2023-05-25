/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:18:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/25 10:56:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_words(char *filename)
{
	int		width;
	int		fd;
	char	*line;
	int		i;

	fd = open(filename, O_RDONLY, 0);
	width = get_width(filename);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		i = word_count(line);	
		if (i != count)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	free(line);
	return (0);
}
