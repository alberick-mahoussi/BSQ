/*
** EPITECH PROJECT, 2022
** nbrs of rows
** File description:
** row at all
*/

#include "my_bsq.h"

int nb_rows(char *str)
{
    int i;
    int save;

    for (i = 0, save = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            save = save + 1;
    if (str[i - 1] == '\n')
        save--;
    return (save);
}
