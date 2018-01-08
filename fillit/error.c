
#include "fillit.h"
#include "libft/libft.h"


/*
**error func when there's nothing to read from stdin
*/

int	ft_nothing_to_read(void)
{
	ft_putendl("Usage error: ./fillit sample");
	return (0);
}

/*
**error func when the file is either empty/has more than 26 tetriminos.
*/

int ft_bad_size(void)
{
	ft_putendl("error");
	return (0);
}

/*
**error func when the file is not formatted well.
*/

int	ft_bad_format_file(void)
{
	ft_putendl("error");
	return (0);
}

/*
**error func when the tetriminos are not formatted well. 
*/

int	ft_bad_format_tetriminos(void)
{
	ft_putendl("error");
	return (0);
}
