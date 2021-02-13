#include "get_next_line.h"

int		get_next_line(char **line)
{
	int		rv;
	int		i = 0;
	char	c;
	char	*buf;

	if (!(buf = (char*)malloc(10000)))
		return (-1);

	*line = buf;

	while ((rv = read(0, &c, 1)) > 0 && c != '\0' && c != '\n')
	{
		buf[i] = c;
		i++;
	}

	buf[i] = '\n';

	if (rv < 0)
		return (-1);

	return (rv ? 1 : 0);
}

#include <stdio.h>

int main(void)
{
	int		rv;
	char	*line;

	while ((rv = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s", line);
	free(line);
}