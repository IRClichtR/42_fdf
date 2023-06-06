#include "fdf.h"

char	**get_file_lines(char *arg)
{
	char	**all_lines;

	all_lines = get_all_lines(arg);
	if (!all_lines)
	{
		ft_putstr_fd("Error: Invalid file\n");
		return (NULL);
	}
	return (all_lines);
}
