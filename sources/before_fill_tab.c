/*
** EPITECH PROJECT, 2022
** before fill tab
** File description:
** fill all tav
*/

#include "my_bsq.h"

void before_fill_tab(char **tab, int posx, int posy, t_b *m)
{
    while (m->save > 0) {
        tab[posx][posy - m->a] = 'x';
        m->a = m->a + 1;
        m->save = m->save - 1;
    }
}
