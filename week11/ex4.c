#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){
    int file_from = open(argv[1], O_RDWR);
    int file_to = open(argv[2], O_RDWR);

    struct stat st1;
    struct stat st2;
    fstat(file_from, &st1);
    fstat(file_to, &st2);

    char *a = mmap(NULL, st1.st_size, PROT_READ, MAP_SHARED, file_from, 0);
    char *b = mmap(NULL, st2.st_size, PROT_WRITE, MAP_SHARED, file_to, 0);

    ftruncate(file_to, strlen(a) * sizeof(char));
    memcpy(b, a, strlen(a) * sizeof(char));
    munmap(b, strlen(a) * sizeof(char));

    close(file_from);
    close(file_to);

    return 0;
}
