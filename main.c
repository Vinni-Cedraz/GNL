/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:46:55 by vcedraz-          #+#    #+#             */
/*   Updated: 2022/10/17 13:16:06 by vcedraz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

// this is an auxiliary function to free iteratively each of the characteres
// in the string passed as an argument

// i'll be using gettime to measure the speed of the program below:

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*nextline;
	int		fd[1024];

	i = -1;
	j = 0;
	*fd = 0;
	nextline = "Hello";
	while (++i < argc - 1)
		fd[i] = open(argv[i + 1], O_RDONLY);
	while (j < i)
	{
		while ((nextline = get_next_line(fd[j])))
		{
			write(1, nextline, ft_strlen(nextline));
			free(nextline);
		}
		close(fd[j]);
		j++;
	}
	return (0);
}
