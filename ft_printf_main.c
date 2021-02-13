#include "ft_printf.h"

int		main(void)
{
	printf("%10.20s\n", "toto");
	ft_printf("%10.20s\n", "toto");
	ft_printf2("%10.20s\n", "toto");
	printf("Magic %s is %5d\n", "number", -42);
	ft_printf("Magic %s is %5d\n", "number", -42);
	ft_printf2("Magic %s is %5d\n", "number", -42);
    printf("Hexadecimal for %.5d is %x\n", -42, 45756);
	ft_printf("Hexadecimal for %.5d is %x\n", -42, 45756);
    ft_printf2("Hexadecimal for %.5d is %x\n", -42, 45756);
}