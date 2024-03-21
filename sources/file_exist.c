/*
** EPITECH PROJECT, 2022
** find file exist
** File description:
** 
*/

#include "my_bsq.h"

char *file_exist(int fd)
{
    if (fd == -1) {
        write(2, "Fichier introuvable\n", 21);
	write(2, "./bsq [map]\n", 13);
        return NULL;
    }
}
