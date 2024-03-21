/*
** EPITECH PROJECT, 2022
** find bigest square
** File description:
** sind square
*/

#include "my_bsq.h"

void find_square(char **tab, int lenght, int width)
{
    t_bsq bsq;

    bsq.len = lenght;
    bsq.wid = width;
    bsq.count = 0;
    bsq.tmp = 0;
    bsq.i = 0;
    while (bsq.i < (bsq.len + 1) * (bsq.wid + 1))
        find_charact(tab, &lenght, &width, &bsq);
    if (bsq.count > 2)
	fill_my_tab(tab, bsq.posx, bsq.posy, bsq.count);
    else
        replace_square(tab);
    bsq.i = 0;
    while (bsq.i <= bsq.len) {
	my_putstr(tab[bsq.i]);
        my_putchar('\n');
        bsq.i = bsq.i + 1;
    }
}
