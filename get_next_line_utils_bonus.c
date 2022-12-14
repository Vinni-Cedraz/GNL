/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:35:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/18 16:18:21 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

typedef unsigned char	t_uc;

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		*(((t_uc *)dst) + i) = *(((t_uc *)src) + i);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*result;
	int		resultlen;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	i = 0;
	resultlen = 0;
	while (s1 && s1[i])
		result[resultlen++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		result[resultlen++] = s2[i++];
	result[resultlen] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (result);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- != 0)
		if (*(t_uc *)s++ == (t_uc)c)
			return ((t_uc *)s - 1);
	return (NULL);
}
