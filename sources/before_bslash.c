/*
** EPITECH PROJECT, 2022
** baslash stop
** File description:
** avoid it
*/

#include "my_bsq.h"

void before_bslash(char *buff, int size)
{
    for (int i = 0; i < size; i++)
        buff[i] = '\0';
}
