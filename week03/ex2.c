#include <stdio.h>

void bubble_sort(int array[], int size){
  for(int i = 1; i < size; i++){
    for(int j = 1; j < size - i; j++){
        if(array[j - 1] > array[j]){
          int tmp = array[j - 1];
          array[j - 1] = array[j];
          array[j] = tmp;
        }
    }
  }
}

int main(){
  int a[10] = {3, 2, 4, 6, 10, 22, 1, 7, 99, 101};
  int size = sizeof(a)/sizeof(int);
  bubble_sort(a, size);
  for(int i = 0; i < size; i++){
    printf("%d ", a[i]);
  }
  return 0;
}
