/*
** EPITECH PROJECT, 2022
** check is empty
** File description:
** empty files
*/

#include "my_bsq.h"

char *empty_file(char c)
{
    if (c == '\0') {
        write(2, EMPTY_FILE, 14);
        write(2, "./bsq [map]\n", 13);
        return NULL;
    }
}
