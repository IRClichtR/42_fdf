#include "libtools.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	t_list *all_lines = get_all_lines(av[1]);
	printf("coucou\n");
	//t_list	*tmp;
	while (all_lines->next != 0)
	{
		printf("%s\n", (char *)all_lines->content);
		//free(all_lines->content);
		//tmp = all_lines;
		all_lines = all_lines->next;
		//free(tmp);
	}
	printf("%s\n", (char *)all_lines->content);
	//free(all_lines->content);
	//free(all_lines);
	return (0);
}
