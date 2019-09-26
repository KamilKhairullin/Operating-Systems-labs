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
    int fork_check = fork();
    if(fork_check > 0){
      write(pipeio[1], first, n);
      close(pipeio[1]);
    }
    else{
      read(pipeio[0], second, n);
      close(pipeio[0]);
      printf("%s\n", second);
    }
    return 0;
}
