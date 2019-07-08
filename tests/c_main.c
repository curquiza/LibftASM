#include <stdio.h>
#include <string.h>

void	ft_puts(int len, char *str);
void	ft_bzero(void *s, size_t size);

int		main(void)
{
	fprintf(stdout, "\nFT_PUTS\n");
	ft_puts(23, "Hello World in main.c!\n");
	fprintf(stdout, "\nFT_BZERO\n");

	char s[4];
	s[0] = 'l';
	s[1] = 'o';
	s[2] = 'l';
	s[3] = '\0';
	fprintf(stdout, "before bzero = %s\n", s);
	ft_bzero(s, 0);
	fprintf(stdout, "after bzero = %s\n", s);
	return 0;
}
