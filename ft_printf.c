#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		g_result;
int		g_width;
int		g_prcsn;

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_result++;
}

void	ft_putstr(char *str, int lngth)
{
	int		i = 0;

	while (str[i] != '\0' && lngth > 0)
	{
		ft_putchar(str[i]);
		i++;
		lngth--;
	}
}

char	*ft_itoa(unsigned long nbr, int base)
{
	unsigned long	tmp = nbr;
	int				lngth = 0;
	char			*str = NULL;

	if (nbr == 0)
		lngth++;
	while (tmp > 0)
	{
		tmp /= base;
		lngth++;
	}
	str = (char*)malloc(lngth + 1);
	str[lngth] = '\0';
	while (lngth > 0)
	{
		str[lngth - 1] = nbr % base;
		if (nbr % base > 9)
			str[lngth - 1] += 'a' - 10;
		else
			str[lngth - 1] += '0';
		nbr /= base;
		lngth--;
	}
	return (str);
}

void	type_s(char *str)
{
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn < lngth) //if given precision is shorter then the string's length 
		lngth = g_prcsn;				//assign it to the string length
	while (g_width > lngth)
	{
		ft_putchar(' ');
		g_width--;
	}
	ft_putstr(str, lngth);
}

void	type_x(unsigned long nbr)
{
	char	*str;

	str = ft_itoa(nbr, 16);
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn > lngth)
		lngth = g_prcsn;
	while (g_width > lngth)
	{
		ft_putchar(' ');
		g_width--;
	}
	while (lngth > ft_strlen(str))
	{
		ft_putchar('0');
		lngth--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}

void	type_d(long nbr)
{
	char	*str;
	int		minus = 0;

	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	str = ft_itoa(nbr, 10);
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn > lngth)
		lngth = g_prcsn;
	if (minus == 1 && g_width > 0)
		g_width--;
	while (g_width > lngth)
	{
		ft_putchar(' ');
		g_width--;
	}
	if (minus == 1)
		ft_putchar('-');
	while (lngth > ft_strlen(str))
	{
		ft_putchar('0');
		lngth--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}

int		ft_printf(const char *str, ... )
{
	g_result = 0;
	int	i = 0;
	va_list	ap;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i+1] != '\0')
		{
			i++;
			g_width = 0;
			g_prcsn = -1; //-1 means that minimal presicion is not set, because 0 is not suitable as an initial value
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_width = g_width * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				g_prcsn = 0;
				i++;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_prcsn = g_prcsn * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				type_s(va_arg(ap, char *));
			else if (str[i] == 'x')
				type_x(va_arg(ap, unsigned int));
			else if (str[i] == 'd')
				type_d(va_arg(ap, int));
			else
				ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_result);
}

#include <stdio.h>

int		main(void)
{
	printf("%10.20s\n", "toto");
	ft_printf("%10.20s\n", "toto");
	// printf("%s", ft_itoa(0x5ab4321, 16));
	printf("Magic %s is %5d\n", "number", -42);
	ft_printf("Magic %s is %5d\n", "number", -42);
	printf("Hexadecimal for %.5d is %x\n", -42, 45756);
	ft_printf("Hexadecimal for %.5d is %x\n", -42, 45756);
}