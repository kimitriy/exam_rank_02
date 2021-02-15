#include "ft_printf.h"


int		g_rv;
int		g_wdth;
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
	g_rv++;
}

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

void	ft_putstr(char *str, int lngth)
{
	int		i = 0;

	while (str[i++] != '\0' && i < lngth)
		ft_putchar(str[i]);
}


int		ft_nbrlen(long nbr, int base)
{
	int		i = 1;

	while (nbr /= base)
		i++;
	return (i);
}

void	ft_putnbr(long nbr, int base, char *dgts)
{
	if (nbr >= base)
		ft_putnbr(nbr / base, base, dgts);
	write(1, &dgts[nbr % base], 1);
	g_rv++;
}

void	type_s(char *str)
{
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn < lngth) //if given precision is shorter then the string's length 
		lngth = g_prcsn;				//assign it to the string length
	while (g_wdth-- > lngth)
		ft_putchar(' ');
	ft_putstr(str, lngth);
}

void	type_x(unsigned long nbr)
{
	int		lngth = ft_nbrlen(nbr, 16);

	if (g_prcsn != -1 && g_prcsn > lngth)
		lngth = g_prcsn;
	while (g_wdth-- > lngth)
		ft_putchar(' ');
	while (lngth-- > ft_nbrlen(nbr, 16))
		ft_putchar('0');
	ft_putnbr(nbr, 16, "0123456789abcdef");
}

void	type_d(long nbr)
{
	int		minus = 0;

	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	int		lngth = ft_nbrlen(nbr, 10);
	if (g_prcsn != -1 && g_prcsn > lngth)
		lngth = g_prcsn;
	if (minus == 1 && g_wdth > 0)
		g_wdth--;
	while (g_wdth-- > lngth)
		ft_putchar(' ');
	if (minus == 1)
		ft_putchar('-');
	while (lngth-- > ft_nbrlen(nbr, 10))
		ft_putchar('0');
	ft_putnbr(nbr, 10, "0123456789");
}

int		ft_printf_my(const char *str, ... )
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
	return (g_rv);
}
