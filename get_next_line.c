#include "get_next_line.h"

int		get_next_line(char **line)
{
	char	buf[100000] = {'\0'};
	char	c;
	int		rv = 0;
	int		i = -1;

	while ((rv = read(0, &c, 1)) > 0 && c != '\0' && c != '\n')
		buf[++i] = c;
	*line = buf;
	return (rv < 0 ? -1 : rv);
}

#include <stdio.h>

int main(void)
{
	int		rv;
	char	*line;

	while ((rv = get_next_line(&line)) > 0)
		printf("%s\n", line);
	printf("%s", line);
}



int		get_next_line(char **line)
{
	char	buf[100000] = {'\0'};
	char	c;
	int		rv = 0;
	int		i = -1;

	while ((rv = read(0, &c, 1)) > 0 && c != '\0' && c != '\n')
		buf[++i] = c;
	if (!(*line = (char*)malloc(100000)))
		return (-1);
	i = -1;
	while (buf[++i] != '\0')
		line[0][i] = buf[i];
	line[0][i] = '\0';
	return (rv < 0 ? -1 : rv);
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