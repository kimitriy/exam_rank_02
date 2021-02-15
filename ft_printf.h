#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include <stdio.h> //for main()

int		ft_printf_my(const char *str, ... );

//ft_printf.c
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str, int lngth);
char	*ft_itoa(unsigned long nbr, int base);
void	type_s(char *str);
void	type_x(unsigned long nbr);
void	type_d(long nbr);
int		ft_printf(const char *str, ... );

//ft_printf2.c
int		ft_nbrlen(long nbr, int base);
void	ft_putnbr(long nbr, int base, char *dgts);
int		ft_printf2(const char *line, ... );

#endif