/*
** EPITECH PROJECT, 2022
** find is correct
** File description:
** contains
*/

#include "my_bsq.h"

char *test_char(char c)
{
    if (c != '.' && c != 'o' && c != '\n' && c != '\0') {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        return NULL;
    }
}
