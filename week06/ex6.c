#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main(){
  int pipeio[2];
  int tmp;
  pipe(pipeio);
  printf("Pipe was successfully created\n");

  printf("Child #1 was successfully created\n");
  pid_t child1 = fork();
  pid_t child2;
  printf("Child #2 was successfully created\n");
  child2 = fork();
  if(child1 > 0 && child2 > 0){
    printf("Hello from main process\n");
    write(pipeio[1], &child2, sizeof(child2));
    printf("Parent writes PID of 2nd child\n");
    printf("Parent waits for state changes in second child\n");
    waitpid(child2, &tmp, WUNTRACED);
    printf("Parent gets changes in second child\n");
    exit(0);
  }

  else if(child1 == 0){
    printf("Hello from first child\n");
    read(pipeio[1], &child2, sizeof(child2));
    printf("First process gets second child's PID\n");
    printf("First process sleeps\n");
    sleep(3);
    printf("First process sends signal to second process\n");
    kill(child2, SIGSTOP);
    printf("SIgnal sent\n");
  }

  else if(child2 == 0){
    printf("Hello from second child\n");
    while(1){
      printf("I'm child #2 and I am alive!\n");
      sleep(1);
    }
  }
  return 0;
}
