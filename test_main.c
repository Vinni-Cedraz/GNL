#include "/nfs/homes/vcedraz-/libft_revisited/ft_memcmp.c"
#include <stdio.h>
#include <string.h>
#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	printf("linha 1: %d\n", ft_memcmp("Hello\n", get_next_line(fd), 6));
	printf("linha 2: %d\n", ft_memcmp("World!\n", get_next_line(fd), 7));
	printf("linha 3: %d\n", ft_memcmp("How are you?\n", get_next_line(fd), 13));
	close(fd);
}
