/*#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	left = read_to	_newline(left, fd);
	if (!left)
		return (0);
	line = get_line(line, left);
	if (line[0] == '\0')
		return (free(charleft), 0);
	return (line);
}
*/
