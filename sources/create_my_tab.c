/*
** EPITECH PROJECT, 2022
** create tab
** File description:
** create
*/

#include "my_bsq.h"

char *create_my_tab(char *buff)
{
    char **tab = malloc(sizeof(*tab) * (nb_rows(buff) + 1));
    int i = 0;

    if (tab == NULL)
        return NULL;
    while (i < nb_rows(buff)) {
	mem_for_cols(buff, tab, i);
        i = i + 1;
    }
    buff_to_tab(buff, tab, 0, 0);
    find_square(tab, nb_rows(buff) - 1, rows_len(buff) - 1);
}
