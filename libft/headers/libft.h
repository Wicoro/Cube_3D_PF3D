/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:08:19 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/07 17:01:01 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "color.h"
# include "utils.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_strlen(const char *s);
void				*ft_memset(void *s, int c, int len);
void				*ft_memmove(void *dst, const void *src, int len);
void				*ft_memcpy(void *dst, const void *src, int n);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
void				ft_bzero(void *s, int n);
char				*ft_strdup(const char *s1);
char				*ft_strdup_no_null(const char *s1);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
long				ft_atoi(const char *str);
void				*ft_calloc(int count, int size);
char				*ft_itoa(int n);
void				*ft_memchr(const void *s, int c, int n);
int					ft_memcmp(const void *s1, const void *s2, int n);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlcat(char *dst, const char *src,
						unsigned int dstsize);
int					ft_strlcpy(char *dst, const char *src, int dstsize);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *haystack, const char *needle,
						int len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(const char *s, unsigned int start, int len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_free_array(int ***array, int len);
void				ft_free_tab(char ***tab);
void				ft_free_index(char ***split, int j);
int					ft_isspace(int c);
char				*ft_strndup(const char *s1, int n);
int					ft_strncmp(const char *s1, const char *s2, int n);
char				**ft_msplit(char const *s, char *sep);
void				ft_swap(char **a, char **b);
int					ft_strlen_tab(char **tab);
void				ft_free_str(char **str);
void				ft_free_int(int **ptr);
long				ft_atol(const char *str);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif