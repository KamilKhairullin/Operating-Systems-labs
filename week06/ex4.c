#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ctrl_c(){
  printf("\nCancelled \n");
}

/*
kill -SIGUSR1 <pid> prints
"\nSIGUSR1 signal\n"
*/
void sigusr1(){
    printf("\nSIGUSR1 signal\n");
}

void sigstop(){
    printf("\nSIGSTOP signal\n");
}

void sigkill(){
    printf("\nSIGKILL signal\n");
}


int main(){
    signal(SIGINT, ctrl_c);
    signal(SIGKILL, sigkill);
    signal(SIGSTOP, sigstop);
    signal(SIGUSR1, sigusr1);
    sleep(1000);
}
