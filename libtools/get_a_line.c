/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_a_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:36:35 by ftuernal          #+#    #+#             */
/*   Updated: 2023/07/11 10:28:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

static char	*get_buffer(int fd)
{
	char	*buffer;
	char	*res;
	int		bytes;

	res = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer || !res)
		return (NULL);
	bytes = 1;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = 0;
		res = join_nfree(&res, buffer);
		if (bytes == 0 || ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (free(buffer), res);
}

char	*get_a_line(int fd)
{
	char	*line;
	char	*buffer;
	int		len;

	buffer = get_buffer(fd);
	if (buffer == 0 || buffer[0] == '\0')
		return (free(buffer), NULL);
	len = get_line_size(buffer);
	line = ft_substr(buffer, 0, len);
	free(buffer);
	return (line);
}
