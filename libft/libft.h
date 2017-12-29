/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:49:41 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/17 14:08:57 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# define BUFF_SIZE 10000

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_abs(int n);
size_t			ft_strlen(char *str);
size_t			ft_strlcat(char *s1, const char *s2, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_memcmp(void *s1, void *s2, size_t n);
int				get_next_line(const int fd, char **line);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_putnbr(int nb);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putstr(char *str);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_putendl(char const *s);
void			*ft_memalloc(size_t size);
void			ft_putnexit(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			*ft_bzero(void *str, size_t len);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			*ft_memchr(void *s, int c, size_t n);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_striter(char *s, void (*f)(char *));
void			*ft_memset(void *str, int c, size_t len);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			*ft_memmove(void *dst, void *src, size_t n);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			*ft_strrev(char *str);
char			*ft_strdup(char *src);
char			*ft_strnew(size_t size);
char			*ft_strtrim(char const *s);
char			*ft_strchr(char *str, int c);
char			*ft_strrchr(char *str, int c);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strcsub(char const *s, char c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(char *haystack, char *needle);
char			*ft_strjoin_char(char const *s1, char c);
char			*ft_strncat(char *s1, char *s2, size_t n);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncpy(char *dst, char *src, size_t n);
char			*ft_strjoinfree(char const *s1, char const *s2);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
char			*ft_strnstr(char *haystack, char *needle, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

#endif
