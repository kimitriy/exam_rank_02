#include "get_next_line.h"

int		get_next_line(char **line)
{
	char	buf[1000000] = {'\0'};
	char	c;
	int		rv = 0;
	int		i = -1;

	while ((rv = read(0, &c, 1)) > 0 &&  c!= '\0' && c != '\n')
		buf[++i] = c;
	if (rv < 0)
		return (-1);
	if (!(*line = (char*)malloc(i + 1)))
		return (-1);
	**line = NULL;
	i = 0;
	while (buf[i] != '\0')
	{
		line[0][i] = buf[i];
		i++;
	}
	line[0][i] = '\0';
	return (rv);
}

// int            get_next_line(char **line)
// {
//     int        i;
//     char    *buf;
//     if (!line || !(buf = malloc(10000)) || read(0, buf, 0) != 0)
//         return (-1);
//     *line = buf;
//     i = 0;
//     while ((read(0, &buf[i], 1)) == 1)
//     {
//         if (buf[i] == '\n')
//         {
//             buf[i] = '\0';
//             return (1);
//         }
//         i++;
//     }
//     buf[i] = '\0';
//     return (0);
// }


// int		get_next_line(char **line)
// {
// 	char	c;
// 	char	*buf;
// 	int		rv;
// 	int		i = 0;

// 	buf = (char *)malloc(10000);
// 	while ((rv = read(0, &c, 1)) > 0 && c != '\n' && c != '\0')
// 	{
// 		buf[i] = c;
// 		i++;
// 	}
// 	buf[i] = '\0';
// 	if (rv == -1)
// 		return (-1);
// 	*line = buf;
// 	return (rv ? 1 : 0);
// }

// int		get_next_line(char **line)
// {
// 	int	res = 1;
// 	int i = 0;
// 	char *buf;
// 	char c;

// 	buf = malloc(sizeof(char) * 10000);
// 	if (buf == NULL)
// 		return (-1);

// 	while (i < 10000)
// 		buf[i++] = '\0';
	
// 	i = 0;
// 	while (res > 0)
// 	{
// 		res = read(0, &c, 1);
// 		if (res > 0 && c != '\n')
// 			buf[i++] = c;
// 		if (res > 0 && c == '\n')
// 		{
// 			*line = buf;
// 			return (1);
// 		}	
// 	}
// 	*line = buf;
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
//       rveak ;
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

	while (1)
	{
		while ((rv = get_next_line(&line)) > 0)
		{
			printf("%s\n", line);
			free(line);
		}
		printf("%s", line);
		free(line);
	}
	return (0);
}