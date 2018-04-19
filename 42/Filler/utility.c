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
/*
** ft_position give a negative 2 of all the position of my enemie
** negative one to all my position. And zero to all other position.
** In that way I can calculateall the possibility I have to reach my enemie.
*/
void ft_position(t_b *b)
{
    uint16_t i;
    uint16_t j;

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
	fill_board(b);
}
void fill_board(t_b *b)
{
	int16_t i;
	int16_t j;
	//int16_t k;

	i = -1;
	while(++i < b->w)
	{
		j = -1;
		while(++j < b->h)
		{
			if(b->fm[i][j] == -2)
            {
                b->e_x = j;
                b->e_y = i;
				k  = -1;
				
				b->fm[i][j + 1] = (j + 1 < b->w) && (b->fm[i][j + 1] == 0) ? 1 : b->fm[i][j + 1];
				b->fm[i][j - 1] = (j - 1 > 0) && (b->fm[i][j - 1] == 0) ? 1 : b->fm[i][j - 1];
				b->fm[i + 1][j] = ((i + 1 < b->h) && (b->fm[i + 1][j] == 0)) ? 1 : b->fm[i + 1][j];
				b->fm[i - 1][j] = ((i - 1 > 0) && (b->fm[i + 1][j] == 0)) ? 1 : b->fm[i - 1][j];
				
				b->fm[i + 1][j - 1] = (j - 1 > 0) && (b->fm[i][j + 1] == 0) ? 1 : b->fm[i][j + 1];
				b->fm[i][j + 1] = (j + 1 < b->w) && (b->fm[i][j + 1] == 0) ? 1 : b->fm[i][j + 1];
				b->fm[i][j + 1] = (j + 1 < b->w) && (b->fm[i][j + 1] == 0) ? 1 : b->fm[i][j + 1];
				b->fm[i][j + 1] = (j + 1 < b->w) && (b->fm[i][j + 1] == 0) ? 1 : b->fm[i][j + 1];
				break;

			}
				ft_fillboard2(b);
		}
	}

}

void ft_fillboard2(t_b *b)
{
	int16_t i;
	int16_t j;
	
	i = 0;	
	neighbor = 0;
	while (++i < b->h)
	{		j = -1;
		while(++j < b->w)
		{
			b->fm[b->e_x][b->e_y]

		}
	}
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