/*
** EPITECH PROJECT, 2022
** arg number
** File description:
** find
*/

#include "my_bsq.h"

char *find_arg_nbr(int ac)
{
    if (ac != 2) {
        write(2, "./bsq [map]\n", 13);
        return NULL;
    }
}
