/*
** EPITECH PROJECT, 2022
** buff to tab
** File description:
** load map
*/

#include "my_bsq.h"

void buff_to_tab(char *buff, char **tab, int a, int b)
{
    int i;

    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
	i = i + 1;
    i = i + 1;
    empty_file(buff[i + 1]);
    buff_tab(buff, tab, a, b, i);
}
