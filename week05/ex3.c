#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int buffer = 123456;
const int MAX = 2147483647;

void * produce(){
  while(1){
    if(buffer < MAX){
      buffer++;
    }
    else{
      sleep(0.01);
    }
  }
}

void * consume(){
  while(1){
    if(buffer > 0){
      buffer--;
    }
    else{
      sleep(0.01);
    }
  }
}

void * print(){
  while(1){
    printf("Buffer is: %d\n", buffer);
  }
}

int main(){
  pthread_t thread_consumer;
  pthread_t thread_producer;
  pthread_t thread_print;
  pthread_create(&thread_consumer, NULL, consume, NULL);
  pthread_create(&thread_producer, NULL, produce, NULL);
  pthread_create(&thread_print, NULL, print, NULL);
  pthread_exit(NULL);
  //pthread_join(thread_descriptor, NULL);
  return 0;
}
