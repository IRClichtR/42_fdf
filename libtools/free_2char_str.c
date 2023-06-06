#include "libtools.h"

void	free_2char_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] == 0;
		i++;
	}
	free(str[i]);
	free(str);
	str = 0;
}
