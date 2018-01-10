/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:29:53 by bpierce           #+#    #+#             */
/*   Updated: 2017/04/26 23:33:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/bsq.h"

int		validation(char *s)
{
	if (check_first_chars(s) == 0)
	{
		return (0);
	}
	if (check_valid_chars(s) == 0)
	{
		return (0);
	}
	if (check_num_of_lines(s) == 0)
	{
		return (0);
	}
	if (check_for_one_empty(s) == 0)
	{
		return (0);
	}
	if (check_line_accuracy(s) == 0)
	{
		return (0);
	}
	return (1);
}

int		main_some_more(char *buf)
{
	char	*map;
	t_cells	*cells;
	t_best	mybox;

	mybox.c_cell = 0;
	mybox.c_size = 1;
	mybox.best_cell = 0;
	mybox.best_size = 0;
	if (validation(buf) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	map = new_map(buf, num_of_lines(buf));
	cells = create_array(buf, map, line_len(buf), num_of_lines(buf));
	mybox = algor(cells, mybox, line_len(buf), num_of_lines(buf));
	free(cells);
	print_new_map(map, mybox, line_len(buf), full_char(buf));
	ft_putchar('\n');
	return (1);
}

void	main_even_more(char *buf, char *s)
{
	int		fd;
	int		ret;

	fd = open(s, O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	main_some_more(buf);
}

int		main(int argc, char **argv)
{
	int		ret;
	int		i;
	char	buf[BUF_SIZE + 1];

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			main_even_more(buf, argv[i]);
			i++;
			ft_putchar('\n');
		}
	}
	else if (argc == 1)
	{
		ret = read(0, buf, BUF_SIZE);
		while (ret == read(1, buf, BUF_SIZE))
			buf[ret] = '\0';
		main_some_more(buf);
	}
	return (0);
}
