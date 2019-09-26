#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(){
  int fork_check = fork();

  if(fork_check > 0){
    sleep(10);
    kill(fork_check, SIGTERM);
  }
  else{
    while(1){
      printf("I'm alive\n");
      sleep(1);
    }
  }
  return 0;
}
