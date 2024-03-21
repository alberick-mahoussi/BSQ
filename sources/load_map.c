/*
** EPITECH PROJECT, 2022
** load the map
** File description:
** loading
*/

#include "my_bsq.h"

char *load_map(char *buff, char *fullbuffer, int len)
{
    char *new = malloc(sizeof(*new) * (my_strlen(fullbuffer) + len + 1));
    int i = 0;
    int compteur = 0;

    if (new == NULL)
        return NULL;
    while (fullbuffer != NULL && fullbuffer[i] != '\0') {
	new[i] = fullbuffer[i];
        i = i + 1 ;
    }
    free(fullbuffer);
    while (buff[compteur] != '\0') {
        new[i] = buff[compteur];
        i = i + 1;
        compteur = compteur + 1;
    }
    new[i] = '\0';
    return (new);
}

