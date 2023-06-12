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
		if (read_bytes < BUFFER_SIZE)
			break ;
		buffer[BUFFER_SIZE] = '\0';
		all_lines = join_nfree(&all_lines, buffer);
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
/*
t_list	**add_lines(int fd)
{
	t_list	*line;
	t_list	**all_lines;
	char	*tmp;

	all_lines = ft_calloc(1, sizeof(t_list *));
	while (1)
	{
		tmp = get_next_line(fd);
		line = ft_lstnew(tmp);
		free(tmp);
		if (line->content != NULL)
			ft_lstadd_back(all_lines, line);
		else
			break ;
	}
	return (all_lines);
}

t_list	*get_all_lines(char *filename)
{
	t_list	**all_lines;
	t_list	*res;
	int	fd;

	fd = open(filename, O_RDONLY, 0);
	if (fd < 0)
		return (NULL);
	all_lines = add_lines(fd);
	res = *all_lines;
	free(all_lines);
	close(fd);
	return (res);
}
*/
