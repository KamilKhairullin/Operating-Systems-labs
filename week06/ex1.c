#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char first[] = "Hello world";
    int n = strlen(first) + 1;
    char second[n];
    int pipeio[2];
    pipe(pipeio);
    write(pipeio[1], first, n);
    read(pipeio[0], second, n);
    printf("%s\n", second);
    close(pipeio[1]);
    return 0;
}
