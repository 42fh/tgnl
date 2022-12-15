#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int ac, char*av[])
{
	char	*l;
	int		fd;

	fd = open(av[1], O_RDONLY);
	printf("BUFFER:%d\n", BUFFER_SIZE);
	if (fd == -1)
		printf("err\n");
	while ((l = get_next_line(fd)))
	{
		printf("%s", l);
	}
	printf("%s", l);
	printf("%p\n", l);
}