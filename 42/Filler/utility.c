#include "filler.h"

void board_set(char *buff, t_b *b)
{
	uint16_t i;

	i = -1;
	while(++i < b->h)
	{
		get_next_line(0, &buff);
		ft_strcpy(b->fm[i], &(buff[4]));
		free(buff);
	}
	i = 0;
	while(i < b->h) //delete Later
		dprintf(b->fd,"%s\n", b->fm[i++]);
}

void ft_position(t_b *b)
{
    int16_t i;
    int16_t j;
	char c;
    i = -1;
	while (++i < b->h)
	{		j = -1;
		while(++j < b->w)
		{
			if(b->fm[i][j] == 'X')
			{
				b->m_x = j;
				b->m_y = i;
			}
		}
	}
	i = -1;
	while (++i < b->h)
	{		j = -1;
		while(++j < b->w)
		{
			if(b->fm[i][j] == 'O')
			{
				b->e_x = j;
				b->e_y = i;
			}
		}
	}	
    dprintf(b->fd,"\n m_x :%d| m_y : %d | e_x :%d| e_y : %d | k : %d\n", b->m_x, b->m_y, b->e_x, b->e_y, b->w * b->h);
}