#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define BUFF_SIZE 4096

typedef struct  s_bsq {
  int i;
  int count;
  int tmp;
  int tmpwidth;
  int tmplenght;
  int len;
  int wid;
  int posx;
  int posy;
} t_bsq;

int	main(int argc, char** argv);
char	*my_realloc(char *buff, char *fullbuffer, int len);
void	my_bufftotab(char *buff, char **tab, int a, int b);
void	test_read(int read);
void	redirect(char **tab, int lenght, int width);
int	my_remp_tab1(char **tab);
void	my_search(char **tab, int *lenght, int *width, t_bsq *bsq);
void	my_search2(char **tab, int *lenght, int *width, t_bsq *bsq);
void	my_remp_tab(char **tab, int posx, int posy, int count);
int	my_strlenbn(char *str);
int	my_strnbline(char *str);

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; str++)
        write(1, &(str[i]), 1);
}

int my_strlen(char *str)
{
    int k;

    if (str == NULL)
        return (0);
    for (k = 0; str[k] != '\0'; k++);
    return (k);
}

void my_bzero(char *buff, int size)
{
    for (int i = 0; i < size; i++)
        buff[i] = '\0';
}

void my_create_tab(char *buff)
{ 
    char **tab;
    int i;

    i = 0;
    tab = malloc(sizeof(*tab) * (my_strnbline(buff) + 1));
    if (tab == NULL)
        exit(84);
    while (i < my_strnbline(buff)) {
        tab[i] = malloc(sizeof(tab) * (my_strlenbn(buff) + 1));
        if (tab[i] == NULL)
            exit(84);
        i = i + 1;
    }
    my_bufftotab(buff, tab, 0, 0);
    redirect(tab, my_strnbline(buff) - 1, my_strlenbn(buff) - 1);
}

int test_tab(int tmp, char **tab, int width, int lenght)
{
    int i;

    i = 1;
    if (tab[lenght][width] != '.')
        return (0);
    while (i < tmp) {
        if (tab[lenght][width + i] != '.'  || tab[lenght + i][width] != '.')
            return (0);
        i = i + 1;
    }
    return (1);
}

void test_argv(int argc)
{
    if (argc != 2) {
        write(2, "./bsq [map]\n", 13);
        exit(84);
    }
}

void find_file(int fd)
{
    if (fd == -1) {
        write(2, "Fichier introuvable\n", 21);
        write(2, "./bsq [map]\n", 13);
        exit(84);
    }
}

void test_file(char *tab)
{
    if (tab == NULL) {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit(84);
    }
}

void test_char(char c)
{
    if (c != '.' && c != 'o' && c != '\n' && c != '\0') {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit(84);
    }
}

void empty_file(char c)
{
    if (c == '\0') {
        write(2, "Fichier eronné\n", 16);
        write(2, "./bsq [map]\n", 13);
        exit(84);
    }
}

int my_strnbline(char *str)
{
    int i;
    int save;

    save = 0;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            save = save + 1;
        i = i + 1;
    }
    if (str[i - 1] == '\n')
        save = save - 1;
    return (save);
}

int my_strlenbn(char *str)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while (str[i] != '\n') {
        i = i + 1;
        a = a + 1;
    }
    i = i + 1;
    a = a + 1;
    while (str[i] != '\n' && str[i] != '\0')
        i = i + 1;
    return (i - a);
}

void my_remp_tab(char **tab, int posx, int posy, int count)
{
    int i;
    int save;
    int a;

    a = 0;
    save = count - 1;
    i = count - 1;
    while (i > 0) {
        while (save > 0)
        {
            tab[posx][posy - a] = 'x';
            a = a + 1;
            save = save - 1;
        }
        save = count - 1;
        a = 0;
        posx = posx - 1;
        i = i - 1;
    }
}

void my_search2(char **tab, int *lenght, int *width, t_bsq *bsq)
{
    bsq->tmpwidth = *width;
    bsq->tmplenght = *lenght;
    bsq->tmp = 1;
    while (*lenght >= 0 && *width >= 0 && test_tab(bsq->tmp, tab, *width,
                                                   *lenght) == 1) {
        *lenght = *lenght - 1;
        *width = *width - 1;
        bsq->tmp = bsq->tmp + 1;
    }
    if (bsq->tmp >= bsq->count) {
        bsq->count = bsq->tmp;
        bsq->posx = *lenght + bsq->count - 1;
        bsq->posy = *width + bsq->count - 1;
    }
    *width = bsq->tmpwidth;
    *lenght = bsq->tmplenght;
    *width = *width - 1;
}

    void my_search(char **tab, int *lenght, int *width, t_bsq *bsq)
    {
        if (tab[*lenght][*width] == 'o' && *width != 0)
            *width = *width - 1;
        else if (*width == 0) {
            *lenght = *lenght - 1;
            *width = bsq->wid;
        }
        else if (tab[*lenght][*width] == '.')
            my_search2(tab, lenght, width, bsq);
        bsq->i = bsq->i + 1;
    }

int my_remp_tab1(char **tab)
{
    int a;
    int b;
    a = 0;
    b = 0;
    while (tab[a][b] != 0) {
        if (tab[a][b] == '.') {
            tab[a][b] = 'x';
            return (0);
        }
        else if (tab[a][b] == 'o')
            b = b + 1;
        else {
            b = 0;
            a = a + 1;
        }
    }
    return (0);
}

void redirect(char **tab, int lenght, int width)
{
    t_bsq	bsq;

    bsq.len = lenght;
    bsq.wid = width;
    bsq.count = 0;
    bsq.tmp = 0;
    bsq.i = 0;
    while (bsq.i < (bsq.len + 1) * (bsq.wid + 1))
        my_search(tab, &lenght, &width, &bsq);
    if (bsq.count > 2)
        my_remp_tab(tab, bsq.posx, bsq.posy, bsq.count);
    else
        my_remp_tab1(tab);
    bsq.i = 0;
    while (bsq.i <= bsq.len) {
        my_putstr(tab[bsq.i]);
        my_putchar('\n');
        bsq.i = bsq.i + 1;
    }
}

void test_read(int read)
{
    if (read == -1) {
        write(2, "File only\n", 11);
        exit(84);
    }
}

void my_bufftotab(char *buff, char **tab, int a, int b)
{
    int i;

    i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
        i = i + 1;
    i = i + 1;
    empty_file(buff[i + 1]);
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
char *my_realloc(char *buff, char *fullbuffer, int len)
{
    char *new;
    int i;
    int compteur;

    compteur = 0;
    i = 0;
    new = malloc(sizeof(*new) * (my_strlen(fullbuffer) + len + 1));
    if (new == NULL)
        exit(84);
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

int main(int argc, char** argv)
{
    char buff[BUFF_SIZE + 1];
    int len;
    char *extend;
    int	fd;

    test_argv(argc);
    extend = NULL;
    my_bzero(buff, BUFF_SIZE);
    fd = open(argv[1], O_RDONLY);
    find_file(fd);
    while ((len = read(fd, buff, BUFF_SIZE)) > 0) {
        buff[len] = 0;
        extend = my_realloc(buff, extend, len);
        my_bzero(buff, BUFF_SIZE);
    }
    test_read(len);
    test_file(extend);
    my_create_tab(extend);
    free(extend);
    close(fd);
    return (0);
}
