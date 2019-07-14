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
char	*ft_strcpy(char * dst, const char * src);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);

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
	if (str1 == NULL && str2 == NULL)
		return ("OK");
	if ((str1 == NULL && str2 != NULL)
		|| (str1 != NULL && str2 == NULL))
	{
		g_score++;
		return ("NOPE !");
	}
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
	char *ft_str;


	{
		printf("\nFT_BZERO\n");

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"lol\\n\", 4) and ft_bzero(\"lol\\n\", 4) ? ");
		bzero(s, 4);
		ft_bzero(ft_s, 4);
		printf("%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"lol\\n\", 1) and ft_bzero(\"lol\\n\", 1) ? ");
		bzero(s, 1);
		ft_bzero(ft_s, 1);
		printf("%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"lol\\n\", 0) and ft_bzero(\"lol\\n\", 0) ? ");
		bzero(s, (0));
		ft_bzero(ft_s, (0));
		printf("%s\n", assert_eq_str(s, ft_s));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"2\", 1) and ft_bzero(\"2\", 1) ? ");
		bzero(s2, 1);
		ft_bzero(ft_s2, 1);
		printf("%s\n", assert_eq_str(s2, ft_s2));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"2\", 0) and ft_bzero(\"2\", 0) ? ");
		bzero(s2, (0));
		ft_bzero(ft_s2, (0));
		printf("%s\n", assert_eq_str(s2, ft_s2));

		init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
		printf("bzero(\"\", 0) and ft_bzero(\"\", 0) ? ");
		bzero(empty, (0));
		ft_bzero(ft_empty, (0));
		printf("%s\n", assert_eq_str(empty, ft_empty));
	}

	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("\nFT_STRCAT\n");
	printf("strcat(\"\", \"\") == ft_strcat(\"\", \"\") => %s\n", assert_eq_str(strcat(empty, empty2), ft_strcat(ft_empty, ft_empty2)));
	printf("strcat(\"yo\", \"2\") == ft_strcat(\"yo\", \"2\") => %s\n", assert_eq_str(strcat(s1, s2), ft_strcat(ft_s1, ft_s2)));
	printf("strcat(\"\", \"2\") == ft_strcat(\"\", \"2\") => %s\n", assert_eq_str(strcat(empty2, s2), ft_strcat(ft_empty2, ft_s2)));

	printf("\nFT_ISALPHA\n");
	printf("ft_isalpha('a') == isalpha('a') => %s\n", assert_eq(ft_isalpha('a'), isalpha('a')));
	printf("ft_isalpha('Z') == isalpha('Z') => %s\n", assert_eq(ft_isalpha('Z'), isalpha('Z')));
	printf("ft_isalpha('c') == isalpha('c') => %s\n", assert_eq(ft_isalpha('c'), isalpha('c')));
	printf("ft_isalpha('^') == isalpha('^') => %s\n", assert_eq(ft_isalpha('^'), isalpha('^')));
	printf("ft_isalpha(0) == isalpha(0) => %s\n", assert_eq(ft_isalpha(0), isalpha(0)));
	printf("ft_isalpha('}') == isalpha('}') => %s\n", assert_eq(ft_isalpha('}'), isalpha('}')));
	printf("ft_isalpha('*') == isalpha('*') => %s\n", assert_eq(ft_isalpha('*'), isalpha('*')));
	printf("ft_isalpha('9') == isalpha('9') => %s\n", assert_eq(ft_isalpha('9'), isalpha('9')));
	printf("ft_isalpha(-1) == isalpha(-1) => %s\n", assert_eq(ft_isalpha(-1), isalpha(-1)));
	printf("ft_isalpha(128) == isalpha(128) => %s\n", assert_eq(ft_isalpha(128), isalpha(128)));

	printf("\nFT_ISDIGIT\n");
	printf("ft_isdigit('f') == isdigit('f') => %s\n", assert_eq(ft_isdigit('f'), isdigit('f')));
	printf("ft_isdigit('0') == isdigit('0') => %s\n", assert_eq(ft_isdigit('0'), isdigit('0')));
	printf("ft_isdigit('1') == isdigit('1') => %s\n", assert_eq(ft_isdigit('1'), isdigit('1')));
	printf("ft_isdigit('9') == isdigit('9') => %s\n", assert_eq(ft_isdigit('9'), isdigit('9')));
	printf("ft_isdigit(':') == isdigit(':') => %s\n", assert_eq(ft_isdigit(':'), isdigit(':')));
	printf("ft_isdigit(0) == isdigit(0) => %s\n", assert_eq(ft_isdigit(0), isdigit(0)));
	printf("ft_isdigit('|') == isdigit('|') => %s\n", assert_eq(ft_isdigit('|'), isdigit('|')));
	printf("ft_isdigit('*') == isdigit('*') => %s\n", assert_eq(ft_isdigit('*'), isdigit('*')));
	printf("ft_isdigit(-1) == isdigit(-1) => %s\n", assert_eq(ft_isdigit(-1), isdigit(-1)));
	printf("ft_isdigit(128) == isdigit(128) => %s\n", assert_eq(ft_isdigit(128), isdigit(128)));

	printf("\nFT_ISALNUM\n");
	printf("ft_isalnum('a') == isalnum('a') => %s\n", assert_eq(ft_isalnum('a'), isalnum('a')));
	printf("ft_isalnum('Z') == isalnum('Z') => %s\n", assert_eq(ft_isalnum('Z'), isalnum('Z')));
	printf("ft_isalnum('c') == isalnum('c') => %s\n", assert_eq(ft_isalnum('c'), isalnum('c')));
	printf("ft_isalnum('^') == isalnum('^') => %s\n", assert_eq(ft_isalnum('^'), isalnum('^')));
	printf("ft_isalnum(0) == isalnum(0) => %s\n", assert_eq(ft_isalnum(0), isalnum(0)));
	printf("ft_isalnum('}') == isalnum('}') => %s\n", assert_eq(ft_isalnum('}'), isalnum('}')));
	printf("ft_isalnum('*') == isalnum('*') => %s\n", assert_eq(ft_isalnum('*'), isalnum('*')));
	printf("ft_isalnum('9') == isalnum('9') => %s\n", assert_eq(ft_isalnum('9'), isalnum('9')));
	printf("ft_isalnum('1') == isalnum('1') => %s\n", assert_eq(ft_isalnum('1'), isalnum('1')));
	printf("ft_isalnum(-1) == isalnum(-1) => %s\n", assert_eq(ft_isalnum(-1), isalnum(-1)));
	printf("ft_isalnum(128) == isalnum(128) => %s\n", assert_eq(ft_isalnum(128), isalnum(128)));

	printf("\nFT_ISASCII\n");
	printf("ft_isascii('c') == isascii('c') => %s\n", assert_eq(ft_isascii('c'), isascii('c')));
	printf("ft_isascii('9') == isascii('9') => %s\n", assert_eq(ft_isascii('9'), isascii('9')));
	printf("ft_isascii('^') == isascii('^') => %s\n", assert_eq(ft_isascii('^'), isascii('^')));
	printf("ft_isascii(-1) == isascii(-1) => %s\n", assert_eq(ft_isascii(-1), isascii(-1)));
	printf("ft_isascii(120) == isascii(120) => %s\n", assert_eq(ft_isascii(120), isascii(120)));
	printf("ft_isascii(0) == isascii(0) => %s\n", assert_eq(ft_isascii(0), isascii(0)));
	printf("ft_isascii(127) == isascii(127) => %s\n", assert_eq(ft_isascii(127), isascii(127)));
	printf("ft_isascii(128) == isascii(128) => %s\n", assert_eq(ft_isascii(128), isascii(128)));
	printf("ft_isascii(240) == isascii(240) => %s\n", assert_eq(ft_isascii(240), isascii(240)));

	printf("\nFT_ISPRINT\n");
	printf("ft_isprint('c') == isprint('c') => %s\n", assert_eq(ft_isprint('c'), isprint('c')));
	printf("ft_isprint('9') == isprint('9') => %s\n", assert_eq(ft_isprint('9'), isprint('9')));
	printf("ft_isprint('^') == isprint('^') => %s\n", assert_eq(ft_isprint('^'), isprint('^')));
	printf("ft_isprint(-1) == isprint(-1) => %s\n", assert_eq(ft_isprint(-1), isprint(-1)));
	printf("ft_isprint(0) == isprint(0) => %s\n", assert_eq(ft_isprint(0), isprint(0)));
	printf("ft_isprint(31) == isprint(31) => %s\n", assert_eq(ft_isprint(31), isprint(31)));
	printf("ft_isprint(32) == isprint(32) => %s\n", assert_eq(ft_isprint(32), isprint(32)));
	printf("ft_isprint(126) == isprint(126) => %s\n", assert_eq(ft_isprint(126), isprint(126)));
	printf("ft_isprint(127) == isprint(127) => %s\n", assert_eq(ft_isprint(127), isprint(127)));
	printf("ft_isprint(128) == isprint(128) => %s\n", assert_eq(ft_isprint(128), isprint(128)));
	printf("ft_isprint(240) == isprint(240) => %s\n", assert_eq(ft_isprint(240), isprint(240)));

	printf("\nFT_TOUPPER\n");
	printf("ft_toupper('c') == toupper('c') => %s\n", assert_eq(ft_toupper('c'), toupper('c')));
	printf("ft_toupper('C') == toupper('C') => %s\n", assert_eq(ft_toupper('C'), toupper('C')));
	printf("ft_toupper('9') == toupper('9') => %s\n", assert_eq(ft_toupper('9'), toupper('9')));
	printf("ft_toupper('^') == toupper('^') => %s\n", assert_eq(ft_toupper('^'), toupper('^')));
	printf("ft_toupper(-1) == toupper(-1) => %s\n", assert_eq(ft_toupper(-1), toupper(-1)));
	printf("ft_toupper(0) == toupper(0) => %s\n", assert_eq(ft_toupper(0), toupper(0)));
	printf("ft_toupper(32) == toupper(32) => %s\n", assert_eq(ft_toupper(32), toupper(32)));
	printf("ft_toupper(127) == toupper(127) => %s\n", assert_eq(ft_toupper(127), toupper(127)));
	printf("ft_toupper(128) == toupper(128) => %s\n", assert_eq(ft_toupper(128), toupper(128)));
	printf("ft_toupper(240) == toupper(240) => %s\n", assert_eq(ft_toupper(240), toupper(240)));

	printf("\nFT_TOLOWER\n");
	printf("ft_tolower('c') == tolower('c') => %s\n", assert_eq(ft_tolower('c'), tolower('c')));
	printf("ft_tolower('C') == tolower('C') => %s\n", assert_eq(ft_tolower('C'), tolower('C')));
	printf("ft_tolower('9') == tolower('9') => %s\n", assert_eq(ft_tolower('9'), tolower('9')));
	printf("ft_tolower('^') == tolower('^') => %s\n", assert_eq(ft_tolower('^'), tolower('^')));
	printf("ft_tolower(-1) == tolower(-1) => %s\n", assert_eq(ft_tolower(-1), tolower(-1)));
	printf("ft_tolower(0) == tolower(0) => %s\n", assert_eq(ft_tolower(0), tolower(0)));
	printf("ft_tolower(32) == tolower(32) => %s\n", assert_eq(ft_tolower(32), tolower(32)));
	printf("ft_tolower(127) == tolower(127) => %s\n", assert_eq(ft_tolower(127), tolower(127)));
	printf("ft_tolower(128) == tolower(128) => %s\n", assert_eq(ft_tolower(128), tolower(128)));
	printf("ft_tolower(240) == tolower(240) => %s\n", assert_eq(ft_tolower(240), tolower(240)));

	printf("\nFT_PUTS\n");
	printf("Real puts:\n");
	int ret1 = puts("Hello World in main.c!");
	int ret2 = puts("");
	int ret3 = puts(NULL);
	printf("ft_puts:\n");
	int ft_ret1 = ft_puts("Hello World in main.c!");
	int ft_ret2 = ft_puts("");
	int ft_ret3 = ft_puts(NULL);
	printf("puts(\"Hello World in main.c!\\n\") == ft_puts(\"Hello World in main.c!\\n\") => %s\n", assert_eq(ret1, ft_ret1));
	printf("puts(\"\") == ft_puts(\"\") => %s\n", assert_eq(ret2, ft_ret2));
	printf("puts(NULL) == ft_puts(NULL) => %s\n", assert_eq(ret3, ft_ret3));

	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("\nFT_STRLEN\n");
	printf("strlen(\"lol\\n\") == ft_strlen(\"lol\\n\") => %s\n", assert_eq(strlen(s), ft_strlen(s)));
	printf("strlen(\"yo\") == ft_strlen(\"yo\") => %s\n", assert_eq(strlen(s1), ft_strlen(ft_s1)));
	printf("strlen(\"2\") == ft_strlen(\"2\") => %s\n", assert_eq(strlen(s2), ft_strlen(s2)));
	printf("strlen(\"\") == ft_strlen(\"\") => %s\n", assert_eq(strlen(""), ft_strlen("")));
	printf("strlen(\"\") == ft_strlen(\"\") => %s\n", assert_eq(strlen(empty2), ft_strlen(empty2)));

	printf("\nFT_MEMSET\n");
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"lol\\n\", 'a', 2) == ft_memset(\"lol\\n\", 'a', 2) => %s\n", assert_eq_str(memset(s, 'a', 2), ft_memset(ft_s, 'a', 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"lol\\n\", 'a', 4) == ft_memset(\"lol\\n\", 'a', 4) => %s\n", assert_eq_str(memset(s, 'a', 4), ft_memset(ft_s, 'a', 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"lol\\n\", 0, 1) == ft_memset(\"lol\\n\", 0, 1) => %s\n", assert_eq_str(memset(s, 0, 1), ft_memset(ft_s, 0, 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"lol\\n\", 'A', 0) == ft_memset(\"lol\\n\", 'A', 0) => %s\n", assert_eq_str(memset(s, 'A', (0)), ft_memset(ft_s, 'A', (0))));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"\", 'A', 0) == ft_memset(\"\", 'A', 0) => %s\n", assert_eq_str(memset(empty, 'A', (0)), ft_memset(ft_empty, 'A', (0))));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"\", 'A', 2) == ft_memset(\"\", 'A', 2) => %s\n", assert_eq_str(memset(empty2, 'A', 2), ft_memset(ft_empty2, 'A', 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memset(\"\", 0, 2) == ft_memset(\"\", 0, 2) => %s\n", assert_eq_str(memset(empty2, 0, 2), ft_memset(ft_empty2, 0, 2)));

	printf("\nFT_MEMCPY\n");
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"hi\", 2) == ft_memcpy(\"lol\\n\", \"hi\", 2) => %s\n", assert_eq_str(memcpy(s, "hi", 2), ft_memcpy(ft_s, "hi", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"hi\", 1) == ft_memcpy(\"lol\\n\", \"hi\", 1) => %s\n", assert_eq_str(memcpy(s, "hi", 1), ft_memcpy(ft_s, "hi", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"hi\", 0) == ft_memcpy(\"lol\\n\", \"hi\", 0) => %s\n", assert_eq_str(memcpy(s, "hi", 0), ft_memcpy(ft_s, "hi", 0)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"h\", 4) == ft_memcpy(\"lol\\n\", \"h\", 4) => %s\n", assert_eq_str(memcpy(s, "h", 4), ft_memcpy(ft_s, "h", 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"hell\", 4) == ft_memcpy(\"lol\\n\", \"hell\", 4) => %s\n", assert_eq_str(memcpy(s, "hell", 4), ft_memcpy(ft_s, "hell", 4)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"\", 0) == ft_memcpy(\"lol\\n\", \"\", 0) => %s\n", assert_eq_str(memcpy(s, "", 0), ft_memcpy(ft_s, "", 0)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"lol\\n\", \"\", 2) == ft_memcpy(\"lol\\n\", \"\", 2) => %s\n", assert_eq_str(memcpy(s, "", 2), ft_memcpy(ft_s, "", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"\", \"yo\", 2) == ft_memcpy(\"\", \"yo\", 2) => %s\n", assert_eq_str(memcpy(s, "yo", 2), ft_memcpy(ft_s, "yo", 2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"\", \"yo\", 1) == ft_memcpy(\"\", \"yo\", 1) => %s\n", assert_eq_str(memcpy(s, "yo", 1), ft_memcpy(ft_s, "yo", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"\", \"\", 1) == ft_memcpy(\"\", \"\", 1) => %s\n", assert_eq_str(memcpy(s, "", 1), ft_memcpy(ft_s, "", 1)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("memcpy(\"\", \"\", 0) == ft_memcpy(\"\", \"\", 0) => %s\n", assert_eq_str(memcpy(s, "", 0), ft_memcpy(ft_s, "", 0)));

	printf("\nFT_STRDUP\n");
	str = ft_strdup("lol"); ft_str = strdup("lol");
	printf("strdup(\"lol\") == ft_strdup(\"lol\") => %s\n", assert_eq_str(str, ft_str));
	free(str); free(ft_str);
	str = ft_strdup(""); ft_str = strdup("");
	printf("strdup(\"\") == ft_strdup(\"\") => %s\n", assert_eq_str(str, ft_str));
	free(str); free(ft_str);
	str = ft_strdup("1"); ft_str = strdup("1");
	printf("strdup(\"1\") == ft_strdup(\"1\") => %s\n", assert_eq_str(str, ft_str));
	free(str); free(ft_str);

	printf("\nFT_MEMALLOC\n");
	str = ft_memalloc(4); printf("ft_memalloc(4) => DONE\n"); free(str);
	str = ft_memalloc(1); printf("ft_memalloc(1) => DONE\n"); free(str);
	str = ft_memalloc(0); printf("ft_memalloc(0) => DONE\n"); free(str);

	printf("\nFT_STRNEW\n");
	str = ft_strnew(4); printf("ft_strnew(4) => DONE\n"); free(str);
	str = ft_strnew(1); printf("ft_strnew(1) => DONE\n"); free(str);
	str = ft_strnew(0); printf("ft_strnew(0) => DONE\n"); free(str);

	printf("\nFT_STRCPY\n");
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("strcpy(\"lol\\n\", \"2\") == ft_strcpy(\"lol\\n\", \"2\") => %s\n", assert_eq_str(strcpy(s, s2), ft_strcpy(ft_s, ft_s2)));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("strcpy(\"lol\\n\", \"test\") == ft_strcpy(\"lol\\n\", \"test\") => %s\n", assert_eq_str(strcpy(s, "test"), ft_strcpy(ft_s, "test")));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("strcpy(\"lol\\n\", \"\") == ft_strcpy(\"lol\\n\", \"\") => %s\n", assert_eq_str(strcpy(s, ""), ft_strcpy(ft_s, "")));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("strcpy(\"\", \"\") == ft_strcpy(\"\", \"\") => %s\n", assert_eq_str(strcpy(empty, ""), ft_strcpy(ft_empty, "")));
	init(s, ft_s, s1, ft_s1, s2, ft_s2, empty, ft_empty, empty2, ft_empty2);
	printf("strcpy(\"\", \"a\") == ft_strcpy(\"\", \"a\") => %s\n", assert_eq_str(strcpy(empty2, ""), ft_strcpy(ft_empty2, "")));

	printf("\nFT_STRJOIN\n");
	str = ft_strjoin("clem", "et elsa"); printf("ft_strjoin(\"clem\", \"et elsa\") == \"clemet elsa\" => %s\n", assert_eq_str(str, "clemet elsa")); free(str);
	str = ft_strjoin("1", "2"); printf("ft_strjoin(\"1\", \"2\") == \"12\" => %s\n", assert_eq_str(str, "12")); free(str);
	str = ft_strjoin("", "et elsa"); printf("ft_strjoin(\"\", \"et elsa\") == \"et elsa\" => %s\n", assert_eq_str(str, "et elsa")); free(str);
	str = ft_strjoin("clem", ""); printf("ft_strjoin(\"clem\", \"\") == \"clem\" => %s\n", assert_eq_str(str, "clem")); free(str);
	str = ft_strjoin("", ""); printf("ft_strjoin(\"\", \"\") == \"\" => %s\n", assert_eq_str(str, "")); free(str);
	str = ft_strjoin(NULL, "clem"); printf("ft_strjoin(NULL, \"clem\") == NULL => %s\n", assert_eq_str(str, NULL)); free(str);
	str = ft_strjoin("clem", NULL); printf("ft_strjoin(\"clem\", NULL) == NULL => %s\n", assert_eq_str(str, NULL)); free(str);
	str = ft_strjoin(NULL, NULL); printf("ft_strjoin(NULL, NULL) == NULL => %s\n", assert_eq_str(str, NULL)); free(str);

	printf("\nFT_STRCMP\n");
	printf("strcmp(\"test\", \"test\") == ft_strcmp(\"test\", \"test\") => %s\n", assert_eq(strcmp("test", "test"), ft_strcmp("test", "test")));
	printf("strcmp(\"clem\", \"test\") == ft_strcmp(\"clem\", \"test\") => %s\n", assert_eq(strcmp("clem", "test"), ft_strcmp("clem", "test")));
	printf("strcmp(\"lol\", \"lol2\") == ft_strcmp(\"lol\", \"lol2\") => %s\n", assert_eq(strcmp("lol", "lol2"), ft_strcmp("lol", "lol2")));
	printf("strcmp(\"\", \"2\") == ft_strcmp(\"\", \"2\") => %s\n", assert_eq(strcmp("", "2"), ft_strcmp("", "2")));
	printf("strcmp(\"2\", \"\") == ft_strcmp(\"2\", \"\") => %s\n", assert_eq(strcmp("2", ""), ft_strcmp("2", "")));
	printf("strcmp(\"\", \"\") == ft_strcmp(\"\", \"\") => %s\n", assert_eq(strcmp("", ""), ft_strcmp("", "")));

	printf("\nFT_STRCHR\n");
	printf("strchr(\"lol\", 'l') == strchr(\"lol\", 'l') => %s\n", assert_eq_str(strchr("lol", 'l'), ft_strchr("lol", 'l')));
	printf("strchr(\"lol\", 'o') == strchr(\"lol\", 'o') => %s\n", assert_eq_str(strchr("lol", 'o'), ft_strchr("lol", 'o')));
	printf("strchr(\"lol\", 'a') == strchr(\"lol\", 'a') => %s\n", assert_eq_str(strchr("lol", 'a'), ft_strchr("lol", 'a')));
	printf("strchr(\"lol\", 0) == strchr(\"lol\", 0) => %s\n", assert_eq_str(strchr("lol", 0), ft_strchr("lol", 0)));
	printf("strchr(\"\", 0) == strchr(\"\", 0) => %s\n", assert_eq_str(strchr("", 0), ft_strchr("", 0)));
	printf("strchr(\"\", 'a') == strchr(\"\", 'a') => %s\n", assert_eq_str(strchr("", 'a'), ft_strchr("", 'a')));
	printf("strchr(\"c\", 'c') == strchr(\"c\", 'c') => %s\n", assert_eq_str(strchr("c", 'c'), ft_strchr("c", 'c')));
	printf("strchr(\"c\", 'd') == strchr(\"c\", 'd') => %s\n", assert_eq_str(strchr("c", 'd'), ft_strchr("c", 'd')));
	printf("strchr(\"c\", -1) == strchr(\"c\", -1) => %s\n", assert_eq_str(strchr("c", -1), ft_strchr("c", -1)));

	printf("\nFT_ATOI\n");
	printf("atoi(\"123\") == ft_atoi(\"123\") => %s\n", assert_eq(atoi("123"), ft_atoi("123")));
	printf("atoi(\"1\") == ft_atoi(\"1\") => %s\n", assert_eq(atoi("1"), ft_atoi("1")));
	printf("atoi(\"0\") == ft_atoi(\"0\") => %s\n", assert_eq(atoi("0"), ft_atoi("0")));
	printf("atoi(\"-0\") == ft_atoi(\"-0\") => %s\n", assert_eq(atoi("-0"), ft_atoi("-0")));
	printf("atoi(\"2147483647\") == ft_atoi(\"2147483647\") => %s\n", assert_eq(atoi("2147483647"), ft_atoi("2147483647")));
	printf("atoi(\"-2147483648\") == ft_atoi(\"-2147483648\") => %s\n", assert_eq(atoi("-2147483648"), ft_atoi("-2147483648")));
	printf("atoi(\"lol\") == ft_atoi(\"lol\") => %s\n", assert_eq(atoi("lol"), ft_atoi("lol")));
	printf("atoi(\"42lol\") == ft_atoi(\"42lol\") => %s\n", assert_eq(atoi("42lol"), ft_atoi("42lol")));
	printf("atoi(\"lol42\") == ft_atoi(\"lol42\") => %s\n", assert_eq(atoi("lol42"), ft_atoi("lol42")));
	printf("atoi(\"-42\") == ft_atoi(\"-42\") => %s\n", assert_eq(atoi("-42"), ft_atoi("-42")));
	printf("atoi(\"+42\") == ft_atoi(\"+42\") => %s\n", assert_eq(atoi("+42"), ft_atoi("+42")));
	printf("atoi(\"+++++42\") == ft_atoi(\"+++++42\") => %s\n", assert_eq(atoi("+++++42"), ft_atoi("+++++42")));
	printf("atoi(\"     7\") == ft_atoi(\"     7\") => %s\n", assert_eq(atoi("     7"), ft_atoi("     7")));
	printf("atoi(\"\\t-7\") == ft_atoi(\"\\t-7\") => %s\n", assert_eq(atoi("\t-7"), ft_atoi("\t-7")));
	printf("atoi(\"\\v-7\") == ft_atoi(\"\\v-7\") => %s\n", assert_eq(atoi("\v-7"), ft_atoi("\v-7")));
	printf("atoi(\"\\vt-7\") == ft_atoi(\"\\vt-7\") => %s\n", assert_eq(atoi("\vt-7"), ft_atoi("\vt-7")));
	printf("atoi(\"\\n-7\") == ft_atoi(\"\\n-7\") => %s\n", assert_eq(atoi("\n-7"), ft_atoi("\n-7")));

	if (g_score != 0)
		printf(RED"\n%d fail(s) !\n"DEF, g_score);
	else
		printf(GREEN"\n0 fail !\n"DEF);
	return 0;
}
