/*
** EPITECH PROJECT, 2022
** dynamique allocation
** File description:
** for cols of tabs
*/

#include "my_bsq.h"

char *mem_for_cols(char *buff, char **tab, int i)
{
    tab[i] = malloc(sizeof(tab) * (rows_len(buff) + 1));
    if (tab[i] == NULL)
        return NULL;
}
