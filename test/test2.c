#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void) {
    
    int fd;
    char *str;
    fd = open("./test.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    system("leaks a.out");
    return (0);
}