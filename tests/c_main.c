#include <stdio.h>
#include <string.h>

void	ft_puts(int len, char *str);
void	ft_bzero(void *s, size_t size);
char	*ft_strcat(char *s1, char *s2);
int		ft_strlen(char *s);

int		main(void)
{
	char empty[1];
	empty[0] = '\0';

	fprintf(stdout, "\nFT_PUTS\n");
	ft_puts(23, "Hello World in main.c!\n");

	fprintf(stdout, "\nFT_BZERO\n");
	char s[4];
	s[0] = 'l';
	s[1] = 'o';
	s[2] = 'l';
	s[3] = '\0';
	fprintf(stdout, "before ft_bzero = %s\n", s);
	ft_bzero(s, 0);
	fprintf(stdout, "after ft_bzero = %s\n", s);

	fprintf(stdout, "\nFT_STRCAT\n");
	char s1[4];
	s1[0] = 'y';
	s1[1] = 'o';
	s1[2] = '\0';
	s1[3] = '\0';
	char s2[2];
	s2[0] = '2';
	s2[1] = '\0';
	// fprintf(stdout, "ft_strcat(\"lol\", \"2\") = %s\n", ft_strcat(s1, s2));

	fprintf(stdout, "\nFT_STRLEN\n");
	fprintf(stdout, "ft_strlen(s) = %d\n", ft_strlen(s));
	fprintf(stdout, "ft_strlen(s2) = %d\n", ft_strlen(s2));
	fprintf(stdout, "ft_strlen(empty) = %d\n", ft_strlen(empty));

	return 0;
}
