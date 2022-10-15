/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/14 21:58:08 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// \n will be refered to as _n throughout the whole code
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	t_str		line;
	size_t		len;
	static char	*aftbrk[1024];

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line.befr_brk = NULL;
	if (!aftbrk[fd])
		line.wth_all = reading_function(fd);
	else
		line.wth_all = ft_strjoin(aftbrk[fd], reading_function(fd));
	len = ft_strlen(line.wth_all) + 1;
	if (len - 1)
	{
		aftbrk[fd] = linebreaker(line.wth_all, len, 1);
		line.befr_brk = linebreaker(line.wth_all, len, 0);
	}
	if (!(line.wth_all == line.befr_brk))
		free(line.wth_all);
	return (line.befr_brk);
}

char	*reading_function(int fd)
{
	t_str	line;
	size_t	bytes_read;

	line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	bytes_read = read(fd, line.read, BUFFER_SIZE);
	if (BUFFER_SIZE == 1)
	{
		*(line.read + bytes_read) = '\0';
		return (line.read);
	}
	line.befr_brk = malloc(sizeof(char));
	*line.befr_brk = '\0';
	while (bytes_read != 0)
	{
		*(line.read + bytes_read) = '\0';
		line.befr_brk = ft_strjoin(line.befr_brk, line.read);
		if (ft_memchr(line.befr_brk, '\n', ft_strlen(line.befr_brk)))
			break ;
		line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
		bytes_read = read(fd, line.read, BUFFER_SIZE);
	}
	if (bytes_read == 0)
		free(line.read);
	return (line.befr_brk);
}

// big_len already has the +1 for the \0
char	*linebreaker(char *wth_all, size_t big_len, size_t aft_or_not)
{
	char	*lnbrk;
	char	*aftbrk;
	char	*befr_brk;
	int		aftbrk_len;

	if (aft_or_not == 1)
	{
		lnbrk = ft_memchr(wth_all, '\n', big_len);
		aftbrk_len = (wth_all + big_len) - (lnbrk + 1);
		if (!lnbrk || lnbrk == wth_all + big_len)
			return (NULL);
		aftbrk = malloc((aftbrk_len + 1) * sizeof(char));
		ft_memcpy(aftbrk, lnbrk + 1, aftbrk_len);
		return (aftbrk);
	}
	lnbrk = ft_memchr(wth_all, '\n', big_len);
	if (!lnbrk || lnbrk == wth_all + big_len)
		return ((char *)wth_all);
	befr_brk = malloc((lnbrk - wth_all + 2) * sizeof(char));
	ft_memcpy(befr_brk, wth_all, lnbrk - wth_all + 2);
	befr_brk[lnbrk - wth_all + 1] = '\0';
	return (befr_brk);
}
