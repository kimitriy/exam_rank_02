#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	int		c[255] = {0};
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	int		i = 0;
	int		j = 0;

	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j] && c[(int)s1[i]] == 0)
			{
				write(1, &s1[i], 1);
				c[(int)s1[i]] = 1;
			}
			j++;
		}
		i++;
		j = 0;
	}

	write(1, "\n", 1);
	return (0);
}