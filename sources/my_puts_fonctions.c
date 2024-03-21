/*
** EPITECH PROJECT, 2022
** puts fonction
** File description:
** my puts fonction
*/

#include "my_bsq.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; str++)
        write(1, &(str[i]), 1);
}

int my_strlen(char *str)
{
    int k;

    if (str == NULL)
        return (0);
    for (k = 0; str[k] != '\0'; k++);
    return (k);
}
