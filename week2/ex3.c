#include <stdio.h>

void print_triangle(int n){
  int k = n - 1;
  int j = 1;
  for(int i = 0; i < n; i++){
    for(int i = 0; i < k; i++){
      printf(" ");
    }
    for(int i = 0; i < j; i++){
      printf("*");
    }
    for(int i = 0; i < k; i++){
      printf(" ");
    }
    k = k - 1;
    j = j + 2;
    printf("\n");
  }
}

int main(){
  int n;
  scanf("%d", &n);
  print_triangle(n);
  return 0;
}
