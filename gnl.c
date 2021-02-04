#include <stdio.h>
#include "get_next_line.h"

int		get_next_line(char **line)
{
	char	c;
	char	*buf;
	int		rv;
	int		i = 0;

	if (!(buf = (char*)malloc(10000)))
		return (-1);
	*line = buf;
	while ((rv = read(0, &c, 1)) > 0 && c != '\n' && c != '\0')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	if (rv == -1)
		return (-1);
	return (rv ? 1 : 0);
}

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