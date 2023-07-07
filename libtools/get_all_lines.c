/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:01:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/07 14:25:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

char	*add_lines(int fd, int buffer_size)
{
	char	*buffer;
	char	*all_lines;
	int		read_bytes;

	buffer = ft_calloc(buffer_size + 1, sizeof(char));
	all_lines = ft_calloc(1, sizeof(char));
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buffer, buffer_size);
		buffer[read_bytes] = '\0';
		all_lines = join_nfree(&all_lines, buffer);
		if (read_bytes < buffer_size)
			break ;
	}
	free(buffer);
	return (all_lines);
}

static int	get_buffer_size(char *filename)
{
	char	*line;
	int		fd;
	int		buffer_size;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Invalid fd\n", 2);
		return (-1);
	}
	line = get_a_line(fd);
	if (!line)
		return (-1);
	buffer_size = ft_strlen(line);
	close(fd);
	free(line);
	return (buffer_size); 
}

char	**get_all_lines(char *filename)
{
	int		fd;
	int		buffer_size;
	char	*all_lines;
	char	**split_lines;

	buffer_size = get_buffer_size(filename);
	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Invalid fd\n", 2);
		return (NULL);
	}
	if (buffer_size <= 0)
		return (close(fd), NULL);
	all_lines = add_lines(fd, buffer_size);
	split_lines = ft_split(all_lines, '\n');
	free(all_lines);
	close(fd);
	return (split_lines);
}
/*
int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	int	i = 0;
	char	**all_lines = get_all_lines(av[1]);
	while (all_lines[i])
	{
		ft_putstr_fd(all_lines[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	free_2char_str(all_lines);
	return (0);
}
*/
