#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ctrl_c(){
  printf("\nCancelled \n");
}
int main(){
  signal(SIGINT, ctrl_c);
  sleep(100);
  return 0;
}
