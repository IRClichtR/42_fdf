/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:01:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 15:18:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

char	*add_lines(int fd)
{
	char	*buffer;
	char	*all_lines;
	int	read_bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	all_lines = ft_calloc(1, sizeof(char));
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
		all_lines = join_nfree(&all_lines, buffer);
		if (read_bytes < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (all_lines);
}

char	**get_all_lines(char *filename)
{
	int	fd;
	char	*all_lines;
	char	**split_lines;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_putstr_fd("Error: Invalid fd\n", 2);
		return (NULL);
	}
	all_lines = add_lines(fd);
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	return (split_lines);
}
