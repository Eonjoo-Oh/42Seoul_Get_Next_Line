#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void) {
    
    int fd;
    char *str;
    fd = open("./test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("1 : %s", str);
    //system("leaks a.out");
    str = get_next_line(fd);
    printf("2 : %s", str);
    //system("leaks a.out");
    str = get_next_line(fd);
    printf("3 : %s", str);
    // system("leaks a.out");
    str = get_next_line(fd);
    printf("3 : %s", str);
    return (0);
}