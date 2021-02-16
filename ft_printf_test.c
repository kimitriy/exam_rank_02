#include "ft_printf.h"

int		g_rv;
int		g_wdth;
int		g_prcsn;

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_rv++;
}

void	ft_putstr(char *str, int lngth)
{
	int		i = -1;

	while (str[++i] && i < lngth)
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
	if (nbr > base)
		ft_putnbr(nbr / base, base, dgts);
	ft_putchar(dgts[nbr % base]);
}

void	type_s(char *str)
{
	int		lngth = ft_strlen(str);

	if (g_prcsn != -1 && g_prcsn < lngth)
		lngth = g_prcsn;
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
	int		lngth = ft_nbrlen(nbr, 10);

	if (nbr < 0 && (minus = 1))
		nbr *= -1;
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

int		ft_printf(const char *str, ... )
{
	va_list ap;
	int		i = 0;

	g_rv = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			g_wdth = 0;
			g_prcsn = -1;
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_wdth = g_wdth * 10 + (str[i] - '0');
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				g_prcsn = 0;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_prcsn = g_prcsn * 10 + (str[i] - '0');
					i++;
				}
			}
			if (str[i] == 's')
				type_s(va_arg(ap, char *));
			if (str[i] == 'x')
				type_x(va_arg(ap, unsigned int));
			if (str[i] == 'd')
				type_d(va_arg(ap, int));
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (g_rv);
}