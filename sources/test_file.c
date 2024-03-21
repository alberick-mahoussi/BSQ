/*
** EPITECH PROJECT, 2022
** find if is
** File description:
** correct file type
*/

#include "my_bsq.h"

char *test_file(char *tab)
{
    if (tab == NULL) {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        return NULL;
    }
}
