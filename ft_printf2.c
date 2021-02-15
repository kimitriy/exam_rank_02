#include "ft_printf.h"


// int		ft_nbrlen(long nbr, int base)
// {
// 	int		i = 1;

// 	while (nbr /= base)
// 		i++;
// 	return (i);
// }

// void	ft_putnbr(long nbr, int base, char *dgts)
// {
// 	if (nbr >= base)
// 		ft_putnbr(nbr / base, base, dgts);
// 	write(1, &dgts[nbr % base], 1);
// }

int		ft_printf2(const char *line, ... )
{
	va_list		ap;
	char		*str;
	char		*sss;
	long		nbr;
	int			neg;
	int			len;
	int			wdth;
	int			prcsn;
	int			zeros;
	int			spaces;
	int			rv = 0;

	va_start(ap, line);
	str = (char*)line;	

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			neg = 0;
			len = 0; //where a length of string to print out is stored
			wdth = 0;
			prcsn = -1;
			zeros = 0;
			spaces = 0;
			while (*str >= '0' && *str <= '9')
			{
				wdth = wdth * 10 + (*str - '0'); //parses width
				str++;
			}
			if (*str == '.')
			{
				prcsn = 0;
				str++;
				while (*str >= '0' && *str <= '9')
				{
					prcsn = prcsn * 10 + (*str - '0'); //parses precision
					str++;
				}
			}
			if (*str == 's')
			{
				sss = va_arg(ap, char *);
				if (!sss)
					sss = "(null)";
				while (sss[len])
					len++;
			}
			if (*str == 'd')
			{
				nbr = va_arg(ap, int);
				if (nbr < 0)
				{
					nbr = -nbr;
					neg = 1;
				}
				len = ft_nbrlen(nbr, 10) + neg;
			}
			if (*str == 'x')
			{
				nbr = va_arg(ap, unsigned int);
				len = ft_nbrlen(nbr, 16);
			}
			if (prcsn >= len && *str != 's')
				zeros = prcsn - len + neg;
			else if (prcsn > -1 && prcsn < len && *str == 's')
				len = prcsn;
			else if (prcsn == 0 && (*str == 's' || nbr == 0))
				len = 0;
			spaces = wdth - zeros - len;
			while (spaces-- > 0)
				rv += write(1, " ", 1);
			if (neg == 1)
				write(1, "-", 1);
			while (zeros-- > 0)
				rv += write(1, "0", 1);
			if (*str == 's')
				write(1, sss, len);
			else if (len > 0 && *str == 'd')
				ft_putnbr(nbr, 10, "0123456789");
			else if (len > 0 && *str == 'x')
				ft_putnbr(nbr, 16, "0123456789abcdef");
			rv += len;
		}
		else
			rv += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return(rv);
}