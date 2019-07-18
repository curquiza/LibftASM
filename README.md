# LibftASM

## Get static library

```bash
$> git clone https://github.com/curquiza/LibftASM
$> cd LibftASM/
$> make
[...]
```

## Test library

```bash
$> make run_c_tests
```

## Test ft_cat

```bash
$> make run_cat_tests
```

## Implemented Functions
```c
// PART 1
void	ft_bzero(void *s, size_t size);
char	*ft_strcat(char *restrict s1, const char *restrict s2);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_puts(const char *s);

// PART 2
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *b, void *c, size_t len);
char	*ft_strdup(const char *s1);

// PART 3
void	ft_cat(int fd);

// BONUS
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char * dst, const char * src);
char	*ft_strjoin(const char *s1, const char *s2);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int	ft_atoi(const char *str);
```
