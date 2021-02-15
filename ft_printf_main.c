#include "ft_printf.h"

int		main(void)
{
	int		rv1;
	int		rv2;
	int		rv3;
	int		rv4;

	rv1 =  printf("%5.9s\n", "khrenasiki");
	rv2 = ft_printf_my("%5.9s\n", "khrenasiki");
	rv3 = ft_printf("%5.9s\n", "khrenasiki");
	rv4 = ft_printf2("%5.9s\n", "khrenasiki");

	// rv1 = printf("Magic %s is %15.11d\n", "number", -424568578);
	// rv2 = ft_printf_my("Magic %s is %15.11d\n", "number", -424568578);
	// rv3 = ft_printf("Magic %s is %15.11d\n", "number", -424568578);
	// rv4 = ft_printf2("Magic %s is %15.11d\n", "number", -424568578);

	// rv1 = printf("Magic %s is %.5d\n", "number", -42);
	// rv2 = ft_printf_my("Magic %s is %.5d\n", "number", -42);
	// rv3 = ft_printf("Magic %s is %.5d\n", "number", -42);
	// rv4 = ft_printf2("Magic %s is %.5d\n", "number", -42);

    // rv1 = printf("Hexadecimal for %.5d is %.10x\n", -42, 45756);
	// rv2 = ft_printf_my("Hexadecimal for %.5d is %.10x\n", -42, 45756);
    // rv3 = ft_printf("Hexadecimal for %.5d is %.10x\n", -42, 45756);
	// rv4 = ft_printf2("Hexadecimal for %.5d is %.10x\n", -42, 45756);

	printf("printf: %d\n", rv1);
	printf("ft_printf_my: %d\n", rv2);
	printf("ft_printf: %d\n", rv3);
	printf("ft_printf2: %d\n", rv4);
}