/*
** EPITECH PROJECT, 2022
** search dimension
** File description:
** search all
*/

#include "my_bsq.h"

void search_dimension(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    bsq->tmpwidth = *width;
    bsq->tmplenght = *lenght;

    for (bsq->tmp = 1; *lenght >= 0 && *width >= 0 &&
             parse_my_tab(bsq->tmp, tab, *width, *lenght) == 1; bsq->tmp++) {
        *lenght = *lenght - 1;
	*width = *width - 1;
    }
    search_engine(tab, lenght, width, bsq);
    *width = bsq->tmpwidth;
    *lenght = bsq->tmplenght;
    *width = *width - 1;
}
