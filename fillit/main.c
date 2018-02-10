/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 02:28:31 by tadey             #+#    #+#             */
/*   Updated: 2018/01/25 07:14:36 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init(t_board *board)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 104)
	{
		j = 0;
		while (j < 104)
			board->map[i][j++] = '.';
	}
	board->size = 4;
}

static int		get(t_tetris *alst, int i)
{
	int			count;
	t_tetris	*current;

	count = 0;
	current = alst;
	while (current)
	{
		current = current->next;
		count++;
	}
	while ((i * i) < 4 * count)
		i++;
	return (i);
}

static void		print(t_board *board)
{
	int		i;

	i = -1;
	while (++i < (board->size + 1) * board->size)
		if (i % (board->size + 1) == board->size)
			ft_putchar('\n');
		else
			ft_putchar(board->map[i / (board->size + 1)]\
					[i % (board->size + 1)]);
}

int				main(int argc, char **argv)
{
	char		*file;
	int			fd;
	char		buff[BUFF_SIZE];
	t_tetris	*alst;
	t_board		*board;

	if (argc != 2)
		return (ft_error(2));
	alst = NULL;
	if (!(board = (t_board*)malloc(sizeof(t_board))))
		return ((int)ft_null_err());
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (!(fd = ft_read(fd, buff)))
		return (0);
	if (!(alst = ft_parse_tet(buff, 0, fd)))
		return (0);
	init(board);
	board->size = get(alst, 2);
	solution(&alst, board);
	print(board);
	return (1);
}
