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
    int16_t k;
	int16_t l;
	//int16_t m;

    i = -1;
	while (++i < b->h)
	{		j = -1;
		while(++j < b->w)
		{
			b->fm[i][j] = b->fm[i][j] == '.' ? 0 : b->fm[i][j];
			if(CE_2(b->fm[i][j], 'X', 'O'))
			{
				b->fm[i][j] = b->fm[i][j] == 'O' && b->p == 1 ? -1 : b->fm[i][j];
				b->fm[i][j] = b->fm[i][j] == 'O' && b->p == 2 ? -2 : b->fm[i][j];
				b->fm[i][j] = b->fm[i][j] == 'X' && b->p == 1 ? -2 : b->fm[i][j];
				b->fm[i][j] = b->fm[i][j] == 'X' && b->p == 2 ? -1 : b->fm[i][j];
			}	
		}
	}
	ft_printboard(b); //detete it later
	
	i = -1;
	
	while (++i < b->h)
	{		j = -1;
			k  = 1;
			l = -2;
		while(++j < b->w)
		{			
			if((b->fm[i][j] == l) && (b->fm[i][j + 1] != l))
			{
				b->fm[i][j + 1] = k ;
				l = k++;
				k = l + 1;
			}
		}
	}
   // dprintf(b->fd,"\n m_x :%d| m_y : %d | e_x :%d| e_y : %d | k : %d\n", b->m_x, b->m_y, b->e_x, b->e_y, b->w * b->h);
	ft_printboard(b); //detete it later
}
void ft_printboard(t_b *b)
{
	int i;
	int j;

	i = -1;
		dprintf(b->fd, "%c\n", -1);
	
	while(++i < b->h)
	{
		j = -1;
		while(++j < b->w)
			dprintf(b->fd, "%d", b->fm[i][j]);
		dprintf(b->fd, "\n");
	}
}