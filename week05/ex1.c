#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * wait(void * n){
    int * tmp = (int*)n;
    printf("I am thread #%d.\n", *tmp);
}

int main(){
  int n = 7;
  for(int i = 0; i < n; i++){
    pthread_t thread_descriptor;
    pthread_create(&thread_descriptor, NULL, wait, (void*)&i);
    printf("Thread #%d created\n", i);
    pthread_join(thread_descriptor, NULL);
    /*
    pthread_join makes the program stops in order to wait
    for the end of the selected thread & fixes the program to be
    strictly thread 1 created
    */
  }
	return 0;
}
