#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *random_file = fopen("/dev/random", "r");
    FILE *output = fopen("ex1.txt", "w+");
    char *string = malloc(20*sizeof(char));
    fgets(string, 20, random_file);
    fputs(string, output);
    fclose(random_file);
    fclose(output);
    return 0;
}
