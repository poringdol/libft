/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:31:53 by pdemocri          #+#    #+#             */
/*   Updated: 2020/05/01 13:31:57 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <string.h>
# include "libft.h"

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strstr(const char *str1, const char *str2);
char	*ft_strncat(char *dst, const char *src, size_t n);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strcpy(char *dst, const char *src);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
int		ft_islower(int ch);
int		ft_isupper(int ch);
int		ft_isblank(int ch);
int		ft_iscntrl(int ch);
int		ft_isgraph(int ch);
int		ft_isspace(int ch);
int		ft_isxdigit(int ch);
int		ft_strcasecmp(const char *str1, const char *str2);
int		ft_strncasecmp(const char *str1, const char *str2, size_t n);
char	*ft_strcasestr(const char *str1, const char *str2);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);

#endif
