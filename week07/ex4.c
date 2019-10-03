#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void * re_alloc(void * ptr, int size){
  if(ptr == NULL){
    return malloc(size);
  }
  else if(size == 0){
    free(ptr);
    return NULL;
  }
  else{
    int * newptr;
    newptr = (int*)malloc(size);
    for(int i = 0; i < size; i++){
      newptr[i] = ((int*)ptr)[i];
    }
    free(ptr);
    return newptr;
  }
}

int main(){
  int * array = (int*)malloc(5 * sizeof(int));
  for(int i = 0 ; i < 5; i++){
    array[i] = 1001;
  }
  for(int i = 0 ; i < 5; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
  array = re_alloc(array, 8  * sizeof(int));
  for(int i = 0 ; i < 8; i++){
    printf("%d ", array[i]);
  }
  return 0;
}
