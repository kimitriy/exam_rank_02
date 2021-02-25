#include "get_next_line.h"

int     ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char s2)
{
	int		i;
	char	*rv;

	i = -1;
	if (!(rv = malloc((ft_strlen(s1) + 2) * sizeof(char))))
		return (0);
	while (s1[++i] != 0)
		rv[i] = s1[i];
	rv[i++] = s2;
	rv[i] = '\0';
	free(s1);
	return (rv);
}

int  get_next_line(char **line)
{
	char buf;
	int  rv;

	*line = malloc(1 * sizeof(char));
	line[0][0] = 0;
	while ((rv = read(0, &buf, 1)) != 0)
	{
		if (buf == '\n')
			break ;
		*line = ft_strjoin(*line, buf);
	}
	return (rv);
}

#include <stdio.h>

int main(void)
{
    int     i;
    char    *line;
    
    i = 0;
    while (get_next_line(&line) != 0)
    {
        printf("line[%d]: |%s|\n", i, line);
        free(line);
        i++;
    }
    printf("line[%d]: |%s|\n", i, line);
    free(line);
    while (1);
    return (0);
}