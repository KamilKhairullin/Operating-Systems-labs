#include <stdio.h>

void swap(int * a, int * b){
  int c;
  c = *a;
  *a = *b;
  *b = c;
}
int main(){
  int a, b;
  printf("Enter first value: ");
  scanf("%d", &a);
  printf("Enter second value: ");
  scanf("%d", &b);
  swap(&a, &b);
  printf("First value after swap: %d\n", a);
  printf("Second value after swap: %d\n", b);
  return 0;
}
