#include "libtools.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char	**all_lines = get_all_lines(av[1]);
	int i = 0;
	while (all_lines[i])
	{
		printf("%s\n", all_lines[i]);
		i++;
	}
	free_2char_str(all_lines);
	return (0);
}
