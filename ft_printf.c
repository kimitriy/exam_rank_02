#include "ft_printf.h"


int		g_rv;
int		g_wdth;
int		g_prcsn;

// int		ft_strlen(char *str)
// {
// 	int		i = 0;

// 	while (str[i] != '\0')
// 		i++;
// 	return (i);
// }

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// 	g_rv++;
// }

// void	ft_putstr(char *str, int lngth)
// {
// 	int		i = 0;

// 	while (str[i] != '\0' && lngth > 0)
// 	{
// 		ft_putchar(str[i]);
// 		i++;
// 		lngth--;
// 	}
// }

char	*ft_itoa(unsigned long nbr, int base)
{
	int				lngth = 0;
	char			*str = NULL;

	if (nbr == 0)
		lngth++;
	lngth = ft_nbrlen(nbr, base);
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

void	t_s(char *str)
{
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn < lngth) //if given precision is shorter then the string's length 
		lngth = g_prcsn;				//assign it to the string length
	while (g_wdth > lngth)
	{
		ft_putchar(' ');
		g_wdth--;
	}
	ft_putstr(str, lngth);
}

void	t_x(unsigned long nbr)
{
	char	*str;

	str = ft_itoa(nbr, 16);
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn > lngth)
		lngth = g_prcsn;
	while (g_wdth > lngth)
	{
		ft_putchar(' ');
		g_wdth--;
	}
	while (lngth > ft_strlen(str))
	{
		ft_putchar('0');
		lngth--;
	}
	ft_putstr(str, ft_strlen(str));
	free(str);
}

void	t_d(long nbr)
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
	if (minus == 1 && g_wdth > 0)
		g_wdth--;
	while (g_wdth > lngth)
	{
		ft_putchar(' ');
		g_wdth--;
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
	g_rv = 0;
	int	i = 0;
	va_list	ap;

	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			g_wdth = 0;
			g_prcsn = -1; //-1 means that minimal presicion is not set, because 0 is not suitable as an initial value
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_wdth = g_wdth * 10 + (str[i] - '0');
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
				t_s(va_arg(ap, char *));
			else if (str[i] == 'x')
				t_x(va_arg(ap, unsigned int));
			else if (str[i] == 'd')
				t_d(va_arg(ap, int));
			else
				ft_putchar(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_rv);
}