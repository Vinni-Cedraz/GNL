/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_line_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:25:47 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/18 16:27:12 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this program writes is a file given as first argument, the number,
// given as second argument, of chars
// of the kind defined by the third argument:

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*buffer;
	int		size;
	int		count;

	size = 1;
	if (argc == 4 && size)
	{
		fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (0);
		i = 0;
		if (!(char *)argv[3])
			return (0);
		buffer = (char *)malloc(size);
		if (atoi(argv[2]) < 4096)
		{
			size = 4096;
			printf("%s\n", "size is defaulting to 4096, try a \
bigger number next time");
		}
		else if (atoi(argv[2]) > __INT_MAX__)
		{
			size = __INT_MAX__;
			printf("%s\n", "size is too big, defaulting to __INT_MAX__,\
try a smaller number next time");
		}
		else
			size = atoi(argv[2]);
		count = 0;
		while (count < size)
		{
			buffer[i] = *argv[3];
			i++;
			count++;
			if (i == size)
			{
				write(fd, buffer, i);
				i = 0;
			}
		}
	}
	else
		printf("%s\n", "Usage:   ./big_line_creator <file> <size> <char>");
	return (0);
}
