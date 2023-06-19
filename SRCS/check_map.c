#include "fdf.h"

int	check_map(char **all_lines)
{
	if (check_words(all_lines) == 1)
		return (1);
	if ((ft_strchr(all_lines[0], ',') != 0 && check_coord(all_lines) == 1)
		|| check_z(all_lines) == 1)
		return (1);
	else
	{
		free_2char_str(all_lines);
		ft_putstr_fd("Error: Invalid map\n", 2);
		return (-1);
	}
}
