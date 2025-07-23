/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norban <norban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:47 by stdevis           #+#    #+#             */
/*   Updated: 2025/07/23 16:46:07 by norban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef MAX_BUFFER_SIZE
#  define MAX_BUFFER_SIZE 8383576
# endif

# ifndef MAX_FD
#  define MAX_FD 10239
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		gnl_ft_strchr(char *s, int c);
int		gnl_ft_strlen(char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_substr(char *s, int start, int len);
char	*gnl_ft_strdup(char *s1);
char	*create_rest(char *line);
char	*read_the_line(int fd, char **rest);
char	*get_next_line(int fd);
void	gnl_ft_free(char **str);
char	*get_the_line(char *rest, char *buff);

#endif