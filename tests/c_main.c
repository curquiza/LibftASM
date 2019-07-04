#include <stdio.h>
#include <string.h>

void	ft_puts(int len, char *str);
void	ft_bzero(void *s, size_t size);

int		main(void)
{
	fprintf(stdout, "\nFT_PUTS\n");
	ft_puts(23, "Hello World in main.c!\n");
	fprintf(stdout, "\nFT_BZERO\n");

	char *s = "test bzero\n";
	ft_bzero(s, strlen(s));
	return 0;
}
