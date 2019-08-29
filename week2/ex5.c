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

void print_right_triangle(int n){
  int k = n - 1;
  int j = 1;
  for(int i = 0; i < n; i++){
    for(int i = 0; i < j; i++){
      printf("*");
    }
    for(int i = 0; i < k; i++){
      printf(" ");
    }
    k = k - 1;
    j = j + 1;
    printf("\n");
  }
}

void print_convex(int n){
  int k = n - 1;
  int j = 1;
  for(int i = 0; i < n / 2 + 1; i++){
    for(int i = 0; i < j; i++){
      printf("*");
    }
    for(int i = 0; i < k; i++){
      printf(" ");
    }
    k = k - 1;
    j = j + 1;
    printf("\n");
  }

  k = k - 2;
  j = j - 2;
  for(int i = 0; i < n / 2; i++){
    for(int i = 0; i < j; i++){
      printf("*");
    }
    for(int i = 0; i < k; i++){
      printf(" ");
    }
    k = k + 1;
    j = j - 1;
    printf("\n");
  }
}

void print_pillar(int n){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        printf("*");
      }
      printf("\n");
    }
}

int main(){
  printf("Enter key from 1 to 4.\n");
  printf("1 is triangle\n");
  printf("2 is right triangle\n");
  printf("3 is convex\n");
  printf("4 is pillar\n");
  int k;
  scanf("%d", &k);
  int n;
  printf("Enter n: \n");
  scanf("%d", &n);
  switch(k){
    case 1:{
      print_triangle(n);
      break;
    }
    case 2:{
      print_right_triangle(n);
      break;
    }
    case 3:{
      print_convex(n);
      break;
    }
    case 4:{
      print_pillar(n);
      break;
    }
    default:
      printf("Error\n");
      break;
  }
  return 0;
}
