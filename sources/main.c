/*
** EPITECH PROJECT, 2022
** the main fonction
** File description:
** to execute
*/

#include "my_bsq.h"

int main(int ac, char **av)
{
    char buff[BUFF_SIZE + 1];
    int len;
    char *extend = NULL;;
    int fd = open(av[1], O_RDONLY);

    find_arg_nbr(ac);
    before_bslash(buff, BUFF_SIZE);
    file_exist(fd);
    while ((len = read(fd, buff, BUFF_SIZE)) > 0) {
        buff[len] = 0;
        extend = load_map(buff, extend, len);
        before_bslash(buff, BUFF_SIZE);
    }
    read_return(len);
    test_file(extend);
    create_my_tab(extend);
    free(extend);
    close(fd);
    return (0);
}
