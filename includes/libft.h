#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define FT_SIZE_MAX (size_t)~0

typedef struct		s_list
{
	void    		*content;
	struct s_list	*next;
}			        t_list;

/************************* PART 1 *************************/
void	*ft_memset(void *destination, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *arr, int c, size_t n);
int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
int	ft_strncmp(const char *str1, const char *str2, size_t n);
int	ft_atoi(const char *str);
int	ft_isalpha(int ch);
int	ft_isdigit(int ch);
int	ft_isalnum(int ch);
int	ft_isascii(int ch);
int	ft_isprint(int ch);
int	ft_toupper(int ch);
int	ft_tolower(int ch);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(const char *str);
/************************* PART 2 *************************/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif