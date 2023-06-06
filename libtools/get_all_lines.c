#include "libtools.h"

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
