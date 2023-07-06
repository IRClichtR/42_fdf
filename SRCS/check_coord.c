#include "fdf.h"

static int	check_one_line(char **nbr_str)
{
	int		i;
	char	**cluster;

	i = 0;
	while (nbr_str[i])
	{
		cluster = ft_split(nbr_str[i], ',');
		if (get_len(cluster) > 2)
			return (free_2char_str(cluster), -1);
		if (check_num(cluster[0]) == -1)
			return (free_2char_str(cluster), -1);
		if (get_len(cluster) == 2)
			if (check_hex(cluster[1]) == -1 || check_num(cluster[0]) == -1)
				return (free_2char_str(cluster), -1);
		free_2char_str(cluster);
		i++;
	}
	return (1);
}

int	check_coord(char **all_lines)
{
	int	i;
	char	**all_nb;

	i = 0;
	while (all_lines[i])
	{
		all_nb = ft_split(all_lines[i], ' ');
		if (check_one_line(all_nb) == -1)
			return (free_2char_str(all_nb), -1);
		free_2char_str(all_nb);
		i++;
	}
	return (1);
}
