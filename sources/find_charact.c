/*
** EPITECH PROJECT, 2022
** find obstacle
** File description:
** find normal too
*/

#include "my_bsq.h"

void find_charact(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    if (tab[*lenght][*width] == 'o' && *width != 0)
        *width = *width - 1;
    else if (*width == 0) {
        *lenght = *lenght - 1;
        *width = bsq->wid;
    }
    else if (tab[*lenght][*width] == '.')
        search_dimension(tab, lenght, width, bsq);
    bsq->i = bsq->i + 1;
}
