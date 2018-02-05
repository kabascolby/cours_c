#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
    int i;
	int ret;
	char c;
	int line;
	line = 0;

    if (argc != 2)
		return (ft_error(1));
	fd = open(argv[1], O_RDONLY);
	if (!(ft_boardcheck(&argv[1], fd)))
		return (ft_error(1));
	while ((ret = get_next_line(fd, &argv[1])) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, argv[1]);
			// free(*buff);
			// puts("WHYYYY");
	}
		//printf("[Return: %d] Line #%d: %s\n", ret, ++line, argv[1]);
		if (ret == -1)
			return(ft_error(2));
		return (0);    
}
