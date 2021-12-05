#include "includes/ft_printf.h"
#include "srcs/ft_putptr_len.c"
#include <stdio.h>

int	main()
{


	char str[] = "123";

	int len = ft_printf("%p", str);
	printf("\n\n%i\n\n", len);
	int leni = printf("%p", str);
	printf("\n\n%i\n\n", leni);
}
