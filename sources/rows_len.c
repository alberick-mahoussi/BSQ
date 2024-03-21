/*
** EPITECH PROJECT, 2022
** rows len
** File description:
** get len of rows
*/

#include "my_bsq.h"

int rows_len(char *str)
{
    int i;
    int a;

    for (i = 0, a = 0; str[i] != '\n'; i++, a++);
    i++;
    a++;
    for ( ;str[i] != '\n' && str[i] != '\0'; i++);
    return (i - a);
}
