#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define GREEN	"\033[1;32m"
#define RED		"\033[1;31m"
#define YELLOW	"\033[1;33m"
#define DEF		"\033[0m"

void	ft_bzero(void *s, size_t size);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);

size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *b, void *c, size_t len);
char	*ft_strdup(const char *s1);

void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);

int		g_score = 0;

char	*assert_eq(int ret1, int ret2)
{
	if (ret1 == ret2)
		return ("OK");
	g_score++;
	return ("NOPE !");
}

char	*assert_eq_str(char *str1, char *str2)
{
	if (strcmp(str1, str2) == 0)
		return ("OK");
	g_score++;
	return ("NOPE !");
}

void	init(char *s, char *ft_s, char *s1, char *ft_s1, char *s2, char *ft_s2, char *empty, char *ft_empty, char *empty2, char *ft_empty2)
{
	empty[0] = 0;
	ft_empty[0] = 0;
	empty2[0] = 0;
	empty2[1] = 0;
	empty2[2] = 0;
	ft_empty2[0] = 0;
	ft_empty2[1] = 0;
	ft_empty2[2] = 0;
	s[0] = 'l';
	s[1] = 'o';
	s[2] = 'l';
	s[3] = '\n';
	s[4] = '\0';
	ft_s[0] = 'l';
	ft_s[1] = 'o';
	ft_s[2] = 'l';
	ft_s[3] = '\n';
	ft_s[4] = '\0';
	s1[0] = 'y';
	s1[1] = 'o';
	s1[2] = '\0';
	s1[3] = '\0';
	ft_s1[0] = 'y';
	ft_s1[1] = 'o';
	ft_s1[2] = '\0';
	ft_s1[3] = '\0';
	s2[0] = '2';
	s2[1] = '\0';
	ft_s2[0] = '2';
	ft_s2[1] = '\0';
}

int		main(void)
{
	char empty[1];
	char ft_empty[1];
	char empty2[3];
	char ft_empty2[3];
	char s[5];
	char ft_s[5];
	char s1[4];
	char ft_s1[4];
	char s2[2];
	char ft_s2[2];
	char *str;


	{
		fprintf(stdout, "\nFT_BZERO\n");

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"lol\\n\", 4) and ft_bzero(\"lol\\n\", 4) ? ");
		bzero(s, 4);
		ft_bzero(ft_s, 4);
		fprintf(stdout, "%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"lol\\n\", 1) and ft_bzero(\"lol\\n\", 1) ? ");
		bzero(s, 1);
		ft_bzero(ft_s, 1);
		fprintf(stdout, "%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"lol\\n\", 0) and ft_bzero(\"lol\\n\", 0) ? ");
		bzero(s, (0));
		ft_bzero(ft_s, (0));
		fprintf(stdout, "%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"2\", 1) and ft_bzero(\"2\", 1) ? ");
		bzero(s2, 1);
		ft_bzero(ft_s2, 1);
		fprintf(stdout, "%s\n", assert_eq_str(s2, ft_s2));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"2\", 0) and ft_bzero(\"2\", 0) ? ");
		bzero(s2, (0));
		ft_bzero(ft_s2, (0));
		fprintf(stdout, "%s\n", assert_eq_str(s2, ft_s2));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		fprintf(stdout, "bzero(\"\", 0) and ft_bzero(\"\", 0) ? ");
		bzero(empty, (0));
		ft_bzero(ft_empty, (0));
		fprintf(stdout, "%s\n", assert_eq_str(empty, ft_empty));
	}

	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "\nFT_STRCAT\n");
	fprintf(stdout, "strcat(\"\", \"\") == ft_strcat(\"\", \"\") => %s\n", assert_eq_str(strcat(empty, empty2), ft_strcat(ft_empty, ft_empty2)));
	fprintf(stdout, "strcat(\"yo\", \"2\") == ft_strcat(\"yo\", \"2\") => %s\n", assert_eq_str(strcat(s1, s2), ft_strcat(ft_s1, ft_s2)));
	fprintf(stdout, "strcat(\"\", \"2\") == ft_strcat(\"\", \"2\") => %s\n", assert_eq_str(strcat(empty2, s2), ft_strcat(ft_empty2, ft_s2)));

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

	fprintf(stdout, "\nFT_PUTS\n");
	fprintf(stdout, "Real puts:\n");
	int ret1 = puts("Hello World in main.c!");
	int ret2 = puts("");
	int ret3 = puts(NULL);
	fprintf(stdout, "ft_puts:\n");
	int ft_ret1 = ft_puts("Hello World in main.c!");
	int ft_ret2 = ft_puts("");
	int ft_ret3 = ft_puts(NULL);
	fprintf(stdout, "puts(\"Hello World in main.c!\\n\") == ft_puts(\"Hello World in main.c!\\n\") => %s\n", assert_eq(ret1, ft_ret1));
	fprintf(stdout, "puts(\"\") == ft_puts(\"\") => %s\n", assert_eq(ret2, ft_ret2));
	fprintf(stdout, "puts(NULL) == ft_puts(NULL) => %s\n", assert_eq(ret3, ft_ret3));

	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "\nFT_STRLEN\n");
	fprintf(stdout, "strlen(\"lol\\n\") == ft_strlen(\"lol\\n\") => %s\n", assert_eq(strlen(s), ft_strlen(s)));
	fprintf(stdout, "strlen(\"yo\") == ft_strlen(\"yo\") => %s\n", assert_eq(strlen(s1), ft_strlen(ft_s1)));
	fprintf(stdout, "strlen(\"2\") == ft_strlen(\"2\") => %s\n", assert_eq(strlen(s2), ft_strlen(s2)));
	fprintf(stdout, "strlen(\"\") == ft_strlen(\"\") => %s\n", assert_eq(strlen(""), ft_strlen("")));
	fprintf(stdout, "strlen(\"\") == ft_strlen(\"\") => %s\n", assert_eq(strlen(empty2), ft_strlen(empty2)));

	fprintf(stdout, "\nFT_MEMSET\n");
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"lol\\n\", 'a', 2) == ft_memset(\"lol\\n\", 'a', 2) => %s\n", assert_eq_str(memset(s, 'a', 2), ft_memset(ft_s, 'a', 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"lol\\n\", 'a', 4) == ft_memset(\"lol\\n\", 'a', 4) => %s\n", assert_eq_str(memset(s, 'a', 4), ft_memset(ft_s, 'a', 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"lol\\n\", 0, 1) == ft_memset(\"lol\\n\", 0, 1) => %s\n", assert_eq_str(memset(s, 0, 1), ft_memset(ft_s, 0, 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"lol\\n\", 'A', 0) == ft_memset(\"lol\\n\", 'A', 0) => %s\n", assert_eq_str(memset(s, 'A', (0)), ft_memset(ft_s, 'A', (0))));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"\", 'A', 0) == ft_memset(\"\", 'A', 0) => %s\n", assert_eq_str(memset(empty, 'A', (0)), ft_memset(ft_empty, 'A', (0))));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"\", 'A', 2) == ft_memset(\"\", 'A', 2) => %s\n", assert_eq_str(memset(empty2, 'A', 2), ft_memset(ft_empty2, 'A', 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memset(\"\", 0, 2) == ft_memset(\"\", 0, 2) => %s\n", assert_eq_str(memset(empty2, 0, 2), ft_memset(ft_empty2, 0, 2)));

	fprintf(stdout, "\nFT_MEMCPY\n");
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"hi\", 2) == ft_memcpy(\"lol\\n\", \"hi\", 2) => %s\n", assert_eq_str(memcpy(s, "hi", 2), ft_memcpy(ft_s, "hi", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"hi\", 1) == ft_memcpy(\"lol\\n\", \"hi\", 1) => %s\n", assert_eq_str(memcpy(s, "hi", 1), ft_memcpy(ft_s, "hi", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"hi\", 0) == ft_memcpy(\"lol\\n\", \"hi\", 0) => %s\n", assert_eq_str(memcpy(s, "hi", 0), ft_memcpy(ft_s, "hi", 0)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"h\", 4) == ft_memcpy(\"lol\\n\", \"h\", 4) => %s\n", assert_eq_str(memcpy(s, "h", 4), ft_memcpy(ft_s, "h", 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"hell\", 4) == ft_memcpy(\"lol\\n\", \"hell\", 4) => %s\n", assert_eq_str(memcpy(s, "hell", 4), ft_memcpy(ft_s, "hell", 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"\", 0) == ft_memcpy(\"lol\\n\", \"\", 0) => %s\n", assert_eq_str(memcpy(s, "", 0), ft_memcpy(ft_s, "", 0)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"lol\\n\", \"\", 2) == ft_memcpy(\"lol\\n\", \"\", 2) => %s\n", assert_eq_str(memcpy(s, "", 2), ft_memcpy(ft_s, "", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"\", \"yo\", 2) == ft_memcpy(\"\", \"yo\", 2) => %s\n", assert_eq_str(memcpy(s, "yo", 2), ft_memcpy(ft_s, "yo", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"\", \"yo\", 1) == ft_memcpy(\"\", \"yo\", 1) => %s\n", assert_eq_str(memcpy(s, "yo", 1), ft_memcpy(ft_s, "yo", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"\", \"\", 1) == ft_memcpy(\"\", \"\", 1) => %s\n", assert_eq_str(memcpy(s, "", 1), ft_memcpy(ft_s, "", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	fprintf(stdout, "memcpy(\"\", \"\", 0) == ft_memcpy(\"\", \"\", 0) => %s\n", assert_eq_str(memcpy(s, "", 0), ft_memcpy(ft_s, "", 0)));

	// init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	// fprintf(stdout, "\nFT_STRDUP\n");
	// char *new = ft_strdup(s);
	// // ft_puts(s);
	// free(new);

	fprintf(stdout, "\nFT_MEMALLOC\n");
	str = ft_memalloc(4); fprintf(stdout, "ft_memalloc(4) => YES\n"); free(str);
	str = ft_memalloc(1); fprintf(stdout, "ft_memalloc(1) => YES\n"); free(str);
	str = ft_memalloc(0); fprintf(stdout, "ft_memalloc(0) => YES\n"); free(str);

	fprintf(stdout, "\nFT_strnew\n");
	str = ft_strnew(4); fprintf(stdout, "ft_strnew(4) => YES\n"); free(str);
	str = ft_strnew(1); fprintf(stdout, "ft_strnew(1) => YES\n"); free(str);
	str = ft_strnew(0); fprintf(stdout, "ft_strnew(0) => YES\n"); free(str);

	if (g_score != 0)
		fprintf(stdout, RED"\n%d fail(s) !\n"DEF, g_score);
	else
		fprintf(stdout, GREEN"\n0 fail !\n"DEF);
	return 0;
}
