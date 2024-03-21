/*
** EPITECH PROJECT, 2022
** buff tab
** File description:
** tab
*/

#include "my_bsq.h"

void buff_tab(char *buff, char **tab, int a, int b, int i)
{
    while (buff[i] != '\0') {
        test_char(buff[i]);
	if (buff[i] == '\n' || buff[i] == '\0') {
            tab[a][b] = '\0';
            a = a + 1;
            b = 0;
        } else {
            tab[a][b] = buff[i];
            b = b + 1;
        }
        i = i + 1;
    }
}
