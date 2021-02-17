#include "get_next_line.h"

int		get_next_line(char **line)
{
	char	buf[10000] = {'\0'};
	char	c;
	int		rv = 0;
	int		i = -1;

	while ((rv = read(0, &c, 1)) > 0 && c != '\0' && c != '\n')
		buf[++i] = c;
	*line = buf;
	return (rv < 0 ? -1 : rv);
}

// int		get_next_line(char **line)
// {
// 	char	buf[10000] = {'\0'};
// 	char	c;
// 	int		rv;
// 	int		i = 0;

// 	if (!(*line = (char*)malloc(10000)))
// 		return (-1);
// 	while ((rv = read(0, &c, 1)) > 0 && c != '\0' && c != '\n')
// 		buf[i++] = c;
// 	i = -1;
// 	while (buf[++i] != '\0')
// 		line[0][i] = buf[i];
// 	if (rv == -1)
// 		return (-1);
// 	return (rv ? 1 : 0);
// }

// int		get_next_line(char **line)
// {
// 	int	res = 1;
// 	int i = 0;
// 	char *str;
// 	char c;

// 	str = malloc(sizeof(char) * 10000);
// 	if (str == NULL)
// 		return (-1);
// 	while (i < 10000)
// 		str[i++] = '\0';
// 	i = 0;
// 	while (res > 0)
// 	{
// 		res = read(0, &c, 1);
// 		if (res > 0 && c != '\n')
// 			str[i++] = c;
// 		if (res > 0 && c == '\n')
// 		{
// 			*line = str;
// 			return (1);
// 		}	
// 	}
// 	*line = str;
// 	return (0);
// }

// int		get_next_line(char **line)
// {
//   int i;
//   int ret;
//   char buffer[1000000];
//   char buf;
//   i = 0;
//   while ((ret = read(0, &buf, 1)) != 0)
//   {
//     if (buf == '\n')
//       break ;
//     buffer[i] = buf;
//     i++;
//   }
//   buffer[i] = '\0';
//   *line = (char *)malloc(sizeof(char) * i);
//   i = 0;
//   while (buffer[i] != 0)
//   {
//     line[0][i] = buffer[i];
//     i++;
//   }
//   line[0][i] = '\0';
//   return (ret);
// }

#include <stdio.h>

int main(void)
{
	int		rv;
	char	*line;

	while ((rv = get_next_line(&line)) > 0)
		printf("%s\n", line);
	printf("%s", line);
}