/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/13 16:22:58 by lamkaba2          #+#    #+#             */
/*   Updated: 2017/12/13 22:31:59 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			jp_parse_sudoku_table(int pos[9][9], char **argv);

int			jp_print_sudoku(int pos[9][9]);

void		jp_set_pos(int *pos, int *orig, int i, int check);
