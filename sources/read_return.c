/*
** EPITECH PROJECT, 2022
** read return
** File description:
** read check
*/

#include "my_bsq.h"

char *read_return(int read)
{
    if (read == -1) {
        write(2, WRG_FILE, 11);
        return NULL;
    }
}
