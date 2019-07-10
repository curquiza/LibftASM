#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN	"\033[1;32m"
#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define DEF		"\033[0m"

void	ft_bzero(void *s, size_t size);
char	*ft_strcat(char *s1, char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_puts(int len, char *str);

int		ft_strlen(char *s);

int		g_score = 0;

char	*assert_eq(int ret1, int ret2)
{
	if (ret1 == ret2)
		return ("OK");
	g_score++;
	return ("NOPE !");
}

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
	fprintf(stdout, "ft_isalpha('a') == isalpha('a') => %s\n", assert_eq(ft_isalpha('a'), isalpha('a')));
	fprintf(stdout, "ft_isalpha('Z') == isalpha('Z') => %s\n", assert_eq(ft_isalpha('Z'), isalpha('Z')));
	fprintf(stdout, "ft_isalpha('c') == isalpha('c') => %s\n", assert_eq(ft_isalpha('c'), isalpha('c')));
	fprintf(stdout, "ft_isalpha('^') == isalpha('^') => %s\n", assert_eq(ft_isalpha('^'), isalpha('^')));
	fprintf(stdout, "ft_isalpha(0) == isalpha(0) => %s\n", assert_eq(ft_isalpha(0), isalpha(0)));
	fprintf(stdout, "ft_isalpha('}') == isalpha('}') => %s\n", assert_eq(ft_isalpha('}'), isalpha('}')));
	fprintf(stdout, "ft_isalpha('*') == isalpha('*') => %s\n", assert_eq(ft_isalpha('*'), isalpha('*')));
	fprintf(stdout, "ft_isalpha('9') == isalpha('9') => %s\n", assert_eq(ft_isalpha('9'), isalpha('9')));
	fprintf(stdout, "ft_isalpha(-1) == isalpha(-1) => %s\n", assert_eq(ft_isalpha(-1), isalpha(-1)));
	fprintf(stdout, "ft_isalpha(128) == isalpha(128) => %s\n", assert_eq(ft_isalpha(128), isalpha(128)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISDIGIT\n");
	fprintf(stdout, "ft_isdigit('f') == isdigit('f') => %s\n", assert_eq(ft_isdigit('f'), isdigit('f')));
	fprintf(stdout, "ft_isdigit('0') == isdigit('0') => %s\n", assert_eq(ft_isdigit('0'), isdigit('0')));
	fprintf(stdout, "ft_isdigit('1') == isdigit('1') => %s\n", assert_eq(ft_isdigit('1'), isdigit('1')));
	fprintf(stdout, "ft_isdigit('9') == isdigit('9') => %s\n", assert_eq(ft_isdigit('9'), isdigit('9')));
	fprintf(stdout, "ft_isdigit(':') == isdigit(':') => %s\n", assert_eq(ft_isdigit(':'), isdigit(':')));
	fprintf(stdout, "ft_isdigit(0) == isdigit(0) => %s\n", assert_eq(ft_isdigit(0), isdigit(0)));
	fprintf(stdout, "ft_isdigit('|') == isdigit('|') => %s\n", assert_eq(ft_isdigit('|'), isdigit('|')));
	fprintf(stdout, "ft_isdigit('*') == isdigit('*') => %s\n", assert_eq(ft_isdigit('*'), isdigit('*')));
	fprintf(stdout, "ft_isdigit(-1) == isdigit(-1) => %s\n", assert_eq(ft_isdigit(-1), isdigit(-1)));
	fprintf(stdout, "ft_isdigit(128) == isdigit(128) => %s\n", assert_eq(ft_isdigit(128), isdigit(128)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISALNUM\n");
	fprintf(stdout, "ft_isalnum('a') == isalnum('a') => %s\n", assert_eq(ft_isalnum('a'), isalnum('a')));
	fprintf(stdout, "ft_isalnum('Z') == isalnum('Z') => %s\n", assert_eq(ft_isalnum('Z'), isalnum('Z')));
	fprintf(stdout, "ft_isalnum('c') == isalnum('c') => %s\n", assert_eq(ft_isalnum('c'), isalnum('c')));
	fprintf(stdout, "ft_isalnum('^') == isalnum('^') => %s\n", assert_eq(ft_isalnum('^'), isalnum('^')));
	fprintf(stdout, "ft_isalnum(0) == isalnum(0) => %s\n", assert_eq(ft_isalnum(0), isalnum(0)));
	fprintf(stdout, "ft_isalnum('}') == isalnum('}') => %s\n", assert_eq(ft_isalnum('}'), isalnum('}')));
	fprintf(stdout, "ft_isalnum('*') == isalnum('*') => %s\n", assert_eq(ft_isalnum('*'), isalnum('*')));
	fprintf(stdout, "ft_isalnum('9') == isalnum('9') => %s\n", assert_eq(ft_isalnum('9'), isalnum('9')));
	fprintf(stdout, "ft_isalnum('1') == isalnum('1') => %s\n", assert_eq(ft_isalnum('1'), isalnum('1')));
	fprintf(stdout, "ft_isalnum(-1) == isalnum(-1) => %s\n", assert_eq(ft_isalnum(-1), isalnum(-1)));
	fprintf(stdout, "ft_isalnum(128) == isalnum(128) => %s\n", assert_eq(ft_isalnum(128), isalnum(128)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISASCII\n");
	fprintf(stdout, "ft_isascii('c') == isascii('c') => %s\n", assert_eq(ft_isascii('c'), isascii('c')));
	fprintf(stdout, "ft_isascii('9') == isascii('9') => %s\n", assert_eq(ft_isascii('9'), isascii('9')));
	fprintf(stdout, "ft_isascii('^') == isascii('^') => %s\n", assert_eq(ft_isascii('^'), isascii('^')));
	fprintf(stdout, "ft_isascii(-1) == isascii(-1) => %s\n", assert_eq(ft_isascii(-1), isascii(-1)));
	fprintf(stdout, "ft_isascii(120) == isascii(120) => %s\n", assert_eq(ft_isascii(120), isascii(120)));
	fprintf(stdout, "ft_isascii(0) == isascii(0) => %s\n", assert_eq(ft_isascii(0), isascii(0)));
	fprintf(stdout, "ft_isascii(127) == isascii(127) => %s\n", assert_eq(ft_isascii(127), isascii(127)));
	fprintf(stdout, "ft_isascii(128) == isascii(128) => %s\n", assert_eq(ft_isascii(128), isascii(128)));
	fprintf(stdout, "ft_isascii(240) == isascii(240) => %s\n", assert_eq(ft_isascii(240), isascii(240)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_ISPRINT\n");
	fprintf(stdout, "ft_isprint('c') == isprint('c') => %s\n", assert_eq(ft_isprint('c'), isprint('c')));
	fprintf(stdout, "ft_isprint('9') == isprint('9') => %s\n", assert_eq(ft_isprint('9'), isprint('9')));
	fprintf(stdout, "ft_isprint('^') == isprint('^') => %s\n", assert_eq(ft_isprint('^'), isprint('^')));
	fprintf(stdout, "ft_isprint(-1) == isprint(-1) => %s\n", assert_eq(ft_isprint(-1), isprint(-1)));
	fprintf(stdout, "ft_isprint(0) == isprint(0) => %s\n", assert_eq(ft_isprint(0), isprint(0)));
	fprintf(stdout, "ft_isprint(31) == isprint(31) => %s\n", assert_eq(ft_isprint(31), isprint(31)));
	fprintf(stdout, "ft_isprint(32) == isprint(32) => %s\n", assert_eq(ft_isprint(32), isprint(32)));
	fprintf(stdout, "ft_isprint(126) == isprint(126) => %s\n", assert_eq(ft_isprint(126), isprint(126)));
	fprintf(stdout, "ft_isprint(127) == isprint(127) => %s\n", assert_eq(ft_isprint(127), isprint(127)));
	fprintf(stdout, "ft_isprint(128) == isprint(128) => %s\n", assert_eq(ft_isprint(128), isprint(128)));
	fprintf(stdout, "ft_isprint(240) == isprint(240) => %s\n", assert_eq(ft_isprint(240), isprint(240)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_TOUPPER\n");
	fprintf(stdout, "ft_toupper('c') == toupper('c') => %s\n", assert_eq(ft_toupper('c'), toupper('c')));
	fprintf(stdout, "ft_toupper('C') == toupper('C') => %s\n", assert_eq(ft_toupper('C'), toupper('C')));
	fprintf(stdout, "ft_toupper('9') == toupper('9') => %s\n", assert_eq(ft_toupper('9'), toupper('9')));
	fprintf(stdout, "ft_toupper('^') == toupper('^') => %s\n", assert_eq(ft_toupper('^'), toupper('^')));
	fprintf(stdout, "ft_toupper(-1) == toupper(-1) => %s\n", assert_eq(ft_toupper(-1), toupper(-1)));
	fprintf(stdout, "ft_toupper(0) == toupper(0) => %s\n", assert_eq(ft_toupper(0), toupper(0)));
	fprintf(stdout, "ft_toupper(32) == toupper(32) => %s\n", assert_eq(ft_toupper(32), toupper(32)));
	fprintf(stdout, "ft_toupper(127) == toupper(127) => %s\n", assert_eq(ft_toupper(127), toupper(127)));
	fprintf(stdout, "ft_toupper(128) == toupper(128) => %s\n", assert_eq(ft_toupper(128), toupper(128)));
	fprintf(stdout, "ft_toupper(240) == toupper(240) => %s\n", assert_eq(ft_toupper(240), toupper(240)));

	init(s, s1, s2, empty, empty2);
	fprintf(stdout, "\nFT_TOLOWER\n");
	fprintf(stdout, "ft_tolower('c') == tolower('c') => %s\n", assert_eq(ft_tolower('c'), tolower('c')));
	fprintf(stdout, "ft_tolower('C') == tolower('C') => %s\n", assert_eq(ft_tolower('C'), tolower('C')));
	fprintf(stdout, "ft_tolower('9') == tolower('9') => %s\n", assert_eq(ft_tolower('9'), tolower('9')));
	fprintf(stdout, "ft_tolower('^') == tolower('^') => %s\n", assert_eq(ft_tolower('^'), tolower('^')));
	fprintf(stdout, "ft_tolower(-1) == tolower(-1) => %s\n", assert_eq(ft_tolower(-1), tolower(-1)));
	fprintf(stdout, "ft_tolower(0) == tolower(0) => %s\n", assert_eq(ft_tolower(0), tolower(0)));
	fprintf(stdout, "ft_tolower(32) == tolower(32) => %s\n", assert_eq(ft_tolower(32), tolower(32)));
	fprintf(stdout, "ft_tolower(127) == tolower(127) => %s\n", assert_eq(ft_tolower(127), tolower(127)));
	fprintf(stdout, "ft_tolower(128) == tolower(128) => %s\n", assert_eq(ft_tolower(128), tolower(128)));
	fprintf(stdout, "ft_tolower(240) == tolower(240) => %s\n", assert_eq(ft_tolower(240), tolower(240)));

	if (g_score != 0)
		fprintf(stdout, RED"\n%d fail(s) !\n"DEF, g_score);
	else
		fprintf(stdout, GREEN"\n0 fail !\n"DEF);
	return 0;
}
