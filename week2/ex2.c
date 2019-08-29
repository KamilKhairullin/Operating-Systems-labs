#include <stdio.h>
#include <string.h>

void reverse(char * str){
  for(int i = 0; i < strlen(str); i++){
    printf("%c", str[strlen(str) - (i + 1)]);
  }
}

int main(){
  char a[] = "string for test";
  reverse(a);
  return 0;
}
