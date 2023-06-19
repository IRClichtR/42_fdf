#include "fdf.h"

int	check_coord(char *line)
{
	int	i;
	char	**all_nb;
	char	**chunk_nb;

	all_nb = ft_split(line, ' ');
	i = 0;
	while (all_nb[i])
	{
		chunk_nb = ft_split(all_nb[i], ',');
		if (get_len(chunk_nbr) != 2)
			return(free_2char_str(chunk_nbr), -1);
		if (check_hex(chunk_nbr[1]) == -1 || check_num(chunk_nbr[0]) == -1)
			return(free_2char_str(chunk_nbr), -1);
		free_2char_str(chunk_nbr);
		i++;
	}
	free_2char_str(all_nb);
	return (1);
}
