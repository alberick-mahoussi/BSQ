/*
** EPITECH PROJECT, 2022
** replace no obstacle
** File description:
** replace it
*/

#include "my_bsq.h"

int replace_charact(char **tab, int a, int b)
{
    if (tab[a][b] == '.') {
        tab[a][b] = 'x';
        return (0);
    }
    else if (tab[a][b] == 'o')
        b = b + 1;
    else {
        b = 0;
        a = a + 1;
    }
}