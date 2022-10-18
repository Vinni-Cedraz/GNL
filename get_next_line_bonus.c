/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/17 23:43:38 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

static void free_lst(t_list *lst);

char	*get_next_line(int fd)
{
	t_str		line;
	size_t		len;
	static char	*aftbrk[1024];

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (BUFFER_SIZE == 1)
		return (read_one(fd));
	line.bfr_brk = NULL;
	if (!aftbrk[fd])
		line.wth_all = reading_function(fd);
	else
		line.wth_all = ft_strjoin(aftbrk[fd], reading_function(fd));
	len = ft_strlen(line.wth_all) + 1;
	if (len - 1)
	{
		aftbrk[fd] = linebreaker(line.wth_all, len, 1);
		line.bfr_brk = linebreaker(line.wth_all, len, 0);
	}
	if (!(line.wth_all == line.bfr_brk))
		free(line.wth_all);
	return (line.bfr_brk);
}

char	*reading_function(int fd)
{
	t_str	line;
	size_t	bytes_read;

	line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	bytes_read = read(fd, line.read, BUFFER_SIZE);
	line.bfr_brk = malloc(sizeof(char));
	*line.bfr_brk = '\0';
	while (bytes_read != 0)
	{
		*(line.read + bytes_read) = '\0';
		line.bfr_brk = ft_strjoin(line.bfr_brk, line.read);
		if (ft_memchr(line.bfr_brk, '\n', ft_strlen(line.bfr_brk)))
			break ;
		line.read = malloc(BUFFER_SIZE + 1 * sizeof(char));
		bytes_read = read(fd, line.read, BUFFER_SIZE);
	}
	if (bytes_read == 0)
		free(line.read);
	return (line.bfr_brk);
}

// big_len already has the +1 for the \0
char	*linebreaker(char *wth_all, size_t big_len, size_t aft_or_not)
{
	char	*lnbrk;
	char	*aftbrk;
	char	*bfr_brk;
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
	bfr_brk = malloc((lnbrk - wth_all + 2) * sizeof(char));
	ft_memcpy(bfr_brk, wth_all, lnbrk - wth_all + 2);
	bfr_brk[lnbrk - wth_all + 1] = '\0';
	return (bfr_brk);
}

char	*read_one(int fd)
{
	int		i;
	t_str	line;
	int		bt_rd;
	t_list	*lst;

	i = 0;
	line.read = malloc(sizeof(char));
	lst = lstnew(line.read);
	*line.read = '\0';
	bt_rd = read(fd, line.read, 1);
	while (bt_rd)
	{
		if (line.read[i] == '\n')
		{
			line.read[i + 1] = '\0';
      line.res = strdup(line.read);
      return (free_lst(lst), line.res);
		}
		line.read[++i] = *(char *)malloc(sizeof(char));
    lst_addback(&lst, lstnew(line.read + i));
		bt_rd = read(fd, line.read + i, 1);
	}
	if (!bt_rd && !i)
		return (free_lst(lst), NULL);
	line.read[i] = '\0';
  line.res = strdup(line.read);
  return (free_lst(lst), line.res);
}

static void free_lst(t_list *lst)
{
  t_list	*tmp;

  while (lst)
  {
    tmp = lst;
    lst = lst->next;
    free(tmp);
  }
}
