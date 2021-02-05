#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		g_result;
int		g_width;
int		g_prcsn;

static void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_result++;
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
			g_width = 0;
			g_prcsn = -1; //-1 means that minimal presicion is not set, because 0 is not suitable as an initial value
			while (str[i] >= '0' && str[i] <= '9')
			{
				g_width = g_width * 10 + (g_width - '0');
				i++;
			}
			if (str[i] == '.')
			{
				g_prcsn = 0;
				i++;
				while (str[i] >= '0' && str[i] <= '9')
				{
					g_prcsn = g_prcsn * 10 + (g_prcsn - '0');
					i++;
				}
			}
			if (str[i] == 's')
				ft_printf_s(va_arg(ap, char *));
			else if (str[i] == 'x')
				ft_printf_x(va_arg(ap, unsigned int));
			else if (str[i] == 'd')
				ft_printf_d(va_arg(ap, int));
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
	printf("%10.2s\n", "toto");
	printf("Magic %s is %5d", "number\n", 42);
	printf("Hexadecimal  for %d is %x\n", 42, 42);

}