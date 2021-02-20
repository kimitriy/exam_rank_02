#include "get_next_line.h"

int		get_next_line(char **line)
{
	char	buf[1000000] = {'\0'};
	char	c;
	int		rv = 0;
	int		i = -1;

	while ((rv = read(0, &c, 1)) > 0 && c != '\n')
		buf[++i] = c;

	if (rv < 0)
		return (-1);

	if (!(*line = (char*)malloc(i + 1)))
		return (-1);

	**line = 0;
	
	i = 0;
	while (buf[i] != '\0')
	{
		line[0][i] = buf[i];
		i++;
	}
	line[0][i] = '\0';
	
	return (rv);
}


int		get_next_line(char **line)
{
	int		i = 0;
	char	*buf;

	if (!line || !(buf = malloc(100000)))
    	return (-1);
    *line = buf;
    while ((read(0, &buf[i], 1)) > 0)
    {
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			return (1);
		}
		i++;
	}
	buf[i] = '\0';
	return (0);
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