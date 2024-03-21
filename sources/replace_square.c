/*
** EPITECH PROJECT, 2022
** replace square
** File description:
** replace it
*/

#include "my_bsq.h"

int replace_square(char **tab)
{
    int a = 0;
    int b = 0;

    while (tab[a][b] != 0)
        replace_charact(tab, a, b);
    return (0);
}
