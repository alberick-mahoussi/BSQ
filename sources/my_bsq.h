/*
** EPITECH PROJECT, 2022
** bsq headers
** File description:
** all my files
*/

#ifndef MY_BSQ_H_
    #define MY_BSQ_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>

    #define ERR_OPEN ("Error : Open failed !\n")
    #define ERR_READ ("Error : Invalid return of read !\n")
    #define ERR_DISP ("Can't display")
    #define NBR_ARG ("The querry need less two argument\n")
    #define EMPTY_FILE (" Empty File !\n")
    #define ROWS_IVL ("Error : Invalid size of rows !\n")
    #define WRG_FILE ("File only\n")
    #define FIlE_NOT ("File doesn't exist !\n")
    #define REDF_ARG ("redefine arguments\n")

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

typedef struct  s_b {
    int k;
    int n;
    int x;
    int a;
    int save;
    int compteur;
    int i;
} t_b;

int replace_square(char **tab);
char *file_exist(int fd);
void before_bslash(char *buff, int size);
char *empty_file(char c);
char *read_return(int read);
int replace_charact(char **tab, int a, int b);
void search_dimension(char **tab, int *lenght, int *width, t_bsq *bsq);
char *mem_for_cols(char *buff, char **tab, int i);
void fill_my_tab(char **tab, int posx, int posy, int count);
void before_fill_tab(char **tab, int posx, int posy, t_b *m);
void my_putchar(char c);
void my_putstr(char *str);
char *find_arg_nbr(int ac);
char *load_map(char *buff, char *fullbuffer, int len);
char *create_my_tab(char *buff);
char *read_return(int read);
int nb_rows(char *str);
int rows_len(char *str);
char *test_file(char *tab);
char *test_char(char c);
int parse_my_tab(int tmp, char **tab, int width, int lenght);
void search_engine(char **tab, int *lenght, int *width, t_bsq *bsq);
int my_strlen(char *str);
void buff_tab(char *buff, char **tab, int a, int b, int i);
void buff_to_tab(char *buff, char **tab, int a, int b);
void search_dimension(char **tab, int *lenght, int *width, t_bsq *bsq);
void find_charact(char **tab, int *lenght, int *width, t_bsq *bsq);
void find_square(char **tab, int lenght, int width);    
int main(int ac, char**av);
#endif/*MY_BSQ_H_*/
