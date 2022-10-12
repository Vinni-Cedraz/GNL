/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:35:26 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/10 23:17:34 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef unsigned char	t_byte;
typedef unsigned char	t_uc;

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *(str + i))
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!size || !nmemb)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	while (ptr && nmemb--)
		((t_byte *)ptr)[nmemb] = 0;
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sb;

	if (s)
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		sb = malloc((len + 1) * sizeof(*s));
		if (sb)
		{
			i = 0;
			if (start <= ft_strlen(s))
				while (s[start] && i < len)
					sb[i++] = s[start++];
			sb[i] = '\0';
			return (sb);
		}
	}
	return (NULL);
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
	if (s1)
		free((char *)s1);
	if (s2)
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
