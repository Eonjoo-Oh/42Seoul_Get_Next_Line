#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void) {
    
    int fd;
    char *str;
    fd = open("./test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("1 : %s", str);
    str = get_next_line(fd);
    printf("2 : %s", str);
    str = get_next_line(fd);
    printf("3 : %s", str);
    system("leaks a.out");
    return (0);
}