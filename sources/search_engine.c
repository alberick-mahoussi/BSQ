/*
** EPITECH PROJECT, 2022
** search engine
** File description:
** search
*/

#include "my_bsq.h"

void search_engine(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    if (bsq->tmp >= bsq->count) {
        bsq->count = bsq->tmp;
        bsq->posx = *lenght + bsq->count - 1;
	bsq->posy = *width + bsq->count - 1;
    }
}
