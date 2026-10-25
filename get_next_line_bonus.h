/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalahian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 17:27:15 by yalahian          #+#    #+#             */
/*   Updated: 2026/10/25 18:54:44 by yalahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

// get_next_line.c
int		read_file(int fd, char *buffer, char **stash);
int		read_stash(char **stash, char **line);
char	*get_next_line(int fd);

// get_next_line_utils.c
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strljoin(char *s1, char *s2, size_t s2_len);
char	*ft_strndup(char *s, size_t n);

#endif
