/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:18:09 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/31 14:34:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_charleft(int fd, char **charleft, int r_bytes)
{
	char	*buff;

	if (!(*charleft))
		*charleft = ft_calloc(1, 1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff || !(*charleft))
		return (NULL);
	while (r_bytes > 0)
	{
		r_bytes = read(fd, buff, BUFFER_SIZE);
		if (r_bytes < 0)
		{
			free(*charleft);
			*charleft = NULL;
			break ;
		}
		if (r_bytes == 0)
			return (free(buff), *charleft);
		buff[r_bytes] = '\0';
		*charleft = join_nfree(charleft, buff);
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	return (free(buff), *charleft);
}

char	*get_line(char *charlft, char *line)
{
	int		i;

	if (!charlft)
		return (NULL);
	if (ft_strchr(charlft, '\n') == NULL)
		line = malloc(sizeof(char) * (ft_strlen(charlft) + 1));
	else if (ft_strchr(charlft, '\n') != NULL)
		line = malloc(sizeof(char) * (ft_strchr(charlft, '\n') - charlft) + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (charlft[i] && charlft[i] != '\n')
	{
		line[i] = charlft[i];
		i++;
	}
	if (charlft[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = 0;
	}
	else
		line[i] = 0;
	return (line);
}

char	*get_new_charleft(char **charleft)
{
	char	*new_charleft;
	int		i;
	int		j;

	i = 0;
	while ((*charleft)[i] && (*charleft)[i] != '\n')
		i++;
	if (!(*charleft)[i])
	{
		free(*charleft);
		*charleft = NULL;
		return (NULL);
	}
	new_charleft = malloc(sizeof(char) * (ft_strlen(*charleft) - i + 1));
	i++;
	j = 0;
	while ((*charleft)[i])
		new_charleft[j++] = (*charleft)[i++];
	new_charleft[j] = '\0';
	free(*charleft);
	*charleft = NULL;
	return (new_charleft);
}

char	*get_next_line(int fd)
{
	static char	*charleft;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	charleft = get_charleft(fd, &charleft, 1);
	if (charleft && charleft[0] == '\0')
	{
		free(charleft);
		charleft = NULL;
		return (NULL);
	}
	if (!charleft)
		return (NULL);
	line = get_line(charleft, line);
	if (line[0] == 0)
		return (free(line), NULL);
	charleft = get_new_charleft(&charleft);
	if (line == NULL && charleft)
	{
		free(charleft);
		charleft = NULL;
	}
	return (line);
}
