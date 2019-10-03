#include <stdio.h>
#include <stdlib.h>

void * re_alloc(void * ptr, int size){
  if(ptr == NULL){
    return malloc(size);
  }
  else if(size == 0){
    free(ptr);
    return NULL;
  }
  else{
    free(ptr);
    return malloc(size);
  }
}

int main(){
  int * array = (int*)malloc(10 * sizeof(int));
  re_alloc(array, 15  *sizeof(int));
}
