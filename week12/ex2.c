#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char buffer[2000];
  fgets(buffer, 2000, stdin);
  char * mode = "w+";
  int c = 1;
  if(strcmp(argv[c], "-a") == 0){
    mode = "a+";
    c++;
  }

  for(int i = c; i < argc; i++){
    FILE *file = fopen(argv[i], mode);
    fputs(buffer, file);
    fclose(file);
  }
  fputs(buffer, stdout);
  return 0;
}
