//add helper function from libft
#include <stdio.h>
#include "libftprintf.h"


int	main()
{
	int a = ft_printf("%%%%qqqq");
	printf("\n");
	int b =    printf("%%%%qqqq");
	printf("\n");

	printf("ft_: %d\nstd: %d\n", a, b);
}
