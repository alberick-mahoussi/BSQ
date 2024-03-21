/*
** EPITECH PROJECT, 2022
** fill my tab
** File description:
** fill all tab
*/

#include "my_bsq.h"

void fill_my_tab(char **tab, int posx, int posy, int count)
{
    int i;
    t_b *m;

    m->a = 0;
    m->save = count - 1;
    i = count - 1;
    while (i > 0) {
        before_fill_tab(tab, posx, posy, m);
        m->save = count - 1;
        m->a = 0;
        posx = posx - 1;
        i = i - 1;
    }
}
