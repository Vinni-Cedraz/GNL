/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:49:56 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/11 21:41:19 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// \n will be refered to as _n throughout the whole code
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	t_str		line;
	size_t		len;
	static char	*line_afterbrk[1024];

	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line.next = NULL;
	if (!line_afterbrk[fd])
		line.with_n = reading_function(fd);
	else
		line.with_n = ft_strjoin(line_afterbrk[fd], reading_function(fd));
	len = ft_strlen(line.with_n);
	if (len)
	{
		line_afterbrk[fd] = sbstr_aft_lnbrk(line.with_n, len + 1);
		line.next = sbstr_til_lnbrk(line.with_n, len + 1);
	}
	if (line.with_n == line.next)
		ft_free_arr(line_afterbrk);
	else
		free(line.with_n);
	return (line.next);
}

char	*reading_function(int fd)
{
	size_t	bytes_read;
	t_str	line;

	line.read = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	line.with_n = ft_calloc(sizeof(char), 1);
	bytes_read = read(fd, line.read, BUFFER_SIZE);
	while (bytes_read != 0)
	{
		*(line.read + bytes_read) = '\0';
		line.with_n = ft_strjoin(line.with_n, line.read);
		if (ft_memchr(line.with_n, '\n', ft_strlen(line.with_n)))
			break ;
		line.read = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		bytes_read = read(fd, line.read, BUFFER_SIZE);
	}
	if (bytes_read == 0)
		free(line.read);
	return (line.with_n);
}

// big_len already has the +1 for the \0
char	*sbstr_til_lnbrk(char *line_with_n, size_t big_len)
{
	char	*n_address;

	n_address = ft_memchr(line_with_n, '\n', big_len);
	if (!n_address || n_address == line_with_n + big_len)
		return (line_with_n);
	return (ft_substr(line_with_n, 0, n_address - line_with_n + 1));
}

// big_len already has the +1 for the \0
char	*sbstr_aft_lnbrk(char *ln_with_n, size_t big_len)
{
	char	*n_address;
	int		sbstrlen;

	n_address = ft_memchr(ln_with_n, '\n', big_len);
	sbstrlen = (ln_with_n + big_len) - (n_address + 1);
	if (!n_address || n_address == ln_with_n + big_len)
		return (NULL);
	return (ft_substr(ln_with_n, (int)(n_address - ln_with_n + 1), sbstrlen));
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
}
