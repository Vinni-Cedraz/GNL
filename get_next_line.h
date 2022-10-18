/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:06:38 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/18 16:33:50 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// The *after_n[] attribute of the t_str is used to store the remaining string
// from the previous line read in a static variable, so it can be used in the
// next call of the function. It can receive as index the fd number being read.
typedef struct s_trings
{
	char	*read;
	char	*res;
	char	*wth_all;
	char	*bfr_brk;
}			t_str;

void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
char		*linebreaker(char *wth_all, size_t big_len, size_t aft_or_not);
char		*reading_function(int fd);
size_t		ft_strlen(const char *str);
char		*read_one(int fd);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
#endif
