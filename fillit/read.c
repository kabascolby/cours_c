
#include "fillit.h"
#include "libft/libft.h"

/*
**  func checks if the file is valid by checking if
**  each tetrimino is composed of four rows of five characters, these five
**  characters being either four #'s or .'s followed by a newline '\n'.
**
** 	each tetrimino should be separated by a \n. 
**	if the file is either empty or exceeds 26 tetriminos, it is invalid.
*/

int	ft_validate_file(char buff[], int shift)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5) < 4)
			if (buff[shift + i] != '.' && buff[shift + i] != '#')
				return (0);
		if ((i % 5) == 4 && buff[shift + i] != '\n')
			return (0);
		i++;	
	}
	if (buff[shift + i] && buff[shift + i] != '\n')
		return (0);
	return (1);
}

/*
**  func checks if the tetriminos in the file are
**  valid by counting the total number of neighbors and the total number of
**  sharps ('#').
**
**  neighbors are the sharps ('#') next to a given sharp. 
**	if the number of neighors is 6 or 8, the tetrimino is valid.
**
**  if less than four sharps are found per 20 bytes read, the tetrimino is
**  invalid.
*/

int	ft_validate_tetrimino(char buff[], int shift, int sharp)
{
	int		i;
	int		neighbor;

	i = 0;
	sharp = 0;
	neighbor = 0;
	while (i < 19)
	{
		if (buff[shift + i] == '#')
		{
			if (i + 1 < 19 && (i + 1) % 5 != 4 && buff[shift + i + 1] == '#')
				neighbor++;
			if (i - 1 >= 0 && (i - 1) % 5 != 4 && buff[shift + i - 1] == '#')
				neighbor++;
			if (i + 5 < 19 && buff[shift + i + 5] == '#')
				neighbor++;
			if (i - 5 >= 0 && buff[shift + i - 5] == '#')
				neighbor++;
			sharp++;
		}
		i++;
	}
	if (sharp != 4 || (neighbor != 6 && neighbor != 8))
		return (0);
	return (1);	
}

/*
**	ft_read reads and counts the number of bytes in the file to
**	..check if the tetriminos and files are valid.
*/

int	ft_read(int fd, char buff[])//params- file descriptor & char array
{
	//vars- one to shift bytes and other to store return val of read
	int shift;
	int read_ret;

	shift = 0;//initializing shift to 0
	ft_strclr(buff);//sets every char to \0 in char array buff
	//attempts to read BUFF_SIZE from the file associated with fd, 
	//and places the characters read into buff.
	read_ret = read(fd, buff, BUFF_SIZE);									
	if (read_ret <= 0 || read_ret != 0)
		return (ft_bad_size);
	while (shift < read_ret)
	{
		if(!ft_validate_file(buff, shift))
			return (ft_bad_format_error());
		if (!ft_validate_tetrimino(buff, shift, 0))
			return (ft_bad_format_tetriminos());
		shift += 21;
	}
	if (shift == read_ret)
		return (ft_bad_format());
	return (read_ret);
}
