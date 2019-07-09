#include <stdio.h>
#include <string.h>
#include <ctype.h>

void	ft_bzero(void *s, size_t size);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
char	*ft_strcat(char *s1, char *s2);
void	ft_puts(int len, char *str);

int		ft_strlen(char *s);

void	init(char *s, char *s1, char *s2, char *empty, char *empty2)
{
	empty[0] = 0;
	empty2[0] = 0;
	empty2[1] = 0;
	empty2[2] = 0;
	s[0] = 'l';
	s[1] = 'o';
	s[2] = 'l';
	s[3] = '\0';
	s1[0] = 'y';
	s1[1] = 'o';
	s1[2] = '\0';
	s1[3] = '\0';
	s2[0] = '2';
	s2[1] = '\0';
}

int		main(void)
{
	char empty[1];
	char empty2[3];
	char s[4];
	char s1[4];
	char s2[2];


	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_PUTS\n");
	ft_puts(23, "Hello World in main.c!\n");

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_BZERO\n");
	fprintf(stdout, "Before ft_bzero = %s\n", s);
	ft_bzero(s, 1);
	fprintf(stdout, "After ft_bzero = %s\n", s);

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_STRCAT\n");
	fprintf(stdout, "ft_strcat(empty, empty2) = %s\n", ft_strcat(empty, empty2));
	fprintf(stdout, "ft_strcat(\"lol\", \"2\") = %s\n", ft_strcat(s1, s2));
	fprintf(stdout, "ft_strcat(empty2, s2) = %s\n", ft_strcat(empty2, s2));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_STRLEN\n");
	fprintf(stdout, "ft_strlen(s) = %d\n", ft_strlen(s));
	fprintf(stdout, "ft_strlen(s2) = %d\n", ft_strlen(s2));
	fprintf(stdout, "ft_strlen(empty) = %d\n", ft_strlen(empty));
	fprintf(stdout, "ft_strlen(empty2) = %d\n", ft_strlen(empty2));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISALPHA\n");
	fprintf(stdout, "ft_isalpha('a') == isalpha('a') => %s\n", ft_isalpha('a') == isalpha('a') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('Z') == isalpha('Z') => %s\n", ft_isalpha('Z') == isalpha('Z') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('c') == isalpha('c') => %s\n", ft_isalpha('c') == isalpha('c') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('^') == isalpha('^') => %s\n", ft_isalpha('^') == isalpha('^') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha(0) == isalpha(0) => %s\n", ft_isalpha(0) == isalpha(0) ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('}') == isalpha('}') => %s\n", ft_isalpha('}') == isalpha('}') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('*') == isalpha('*') => %s\n", ft_isalpha('*') == isalpha('*') ? "YES" : "NO");
	fprintf(stdout, "ft_isalpha('9') == isalpha('9') => %s\n", ft_isalpha('9') == isalpha('9') ? "YES" : "NO");

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISALPHA\n");
	fprintf(stdout, "ft_isdigit('f') == isdigit('f') => %s\n", ft_isdigit('f') == isdigit('f') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit('0') == isdigit('0') => %s\n", ft_isdigit('0') == isdigit('0') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit('1') == isdigit('1') => %s\n", ft_isdigit('1') == isdigit('1') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit('9') == isdigit('9') => %s\n", ft_isdigit('9') == isdigit('9') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit(':') == isdigit(':') => %s\n", ft_isdigit(':') == isdigit(':') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit(0) == isdigit(0) => %s\n", ft_isdigit(0) == isdigit(0) ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit('|') == isdigit('|') => %s\n", ft_isdigit('|') == isdigit('|') ? "YES" : "NO");
	fprintf(stdout, "ft_isdigit('*') == isdigit('*') => %s\n", ft_isdigit('*') == isdigit('*') ? "YES" : "NO");

	return 0;
}
