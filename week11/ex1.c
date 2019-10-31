#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>	
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  int file = open(argv[1], O_RDWR);
  struct stat st;
  fstat(file, &st);
  char *a = (char*)mmap(NULL, st.st_size,PROT_WRITE, MAP_SHARED, file, 0);
  strcpy(a, "This is a nice day");
  ftruncate(file, 18);
  munmap(a, 18);
  close(file);
  return 0;
}
