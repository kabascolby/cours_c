#include "filler.h"

void board_set(char *buff, t_b *b)
{
	size_t i;

	b->fm = (char **)malloc(sizeof(char *) * b->h);
	i = -1;
	while (++i < b->h)
		b->fm[i] = ft_strnew(b->w);
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
    unsigned i;
    int k;

    k = ft_strlen(b->fm[0]);
    
    i = 1;
	while (++i < (b->w * b->h))
		if (b->fm[i / k][i % k] == 'O')
		{
			b->m_x = (i / k) + b->w;
			b->m_y = (i % k) + b->h;
		}
    dprintf(b->fd,"\n m_x :%d| m_y : %d | k : %d\n", b->m_x, b->m_y, k);
}