/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaba <lkaba@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:02:07 by lkaba             #+#    #+#             */
/*   Updated: 2017/11/22 16:02:21 by lkaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void decoupeminute(int *heures, int *minutes);

int main()
{
    int H;
    int M;
    H = 0;
    M = 90;
    decoupeminute(&H, &M);

   // printf("%d heures %d minutes", H, M);

    return 0;
}

void decoupeminute(int *heures, int *minutes)
{
    *heures = *minutes / 60;
    *minutes = *minutes % 60;
    printf("%d heures %d minutes\n", *heures, *minutes);
}
