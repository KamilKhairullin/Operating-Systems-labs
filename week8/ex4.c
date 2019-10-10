#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define ONE_MB 1024*1024
int main(){
  struct rusage usage;
  for(int i = 0; i < 10; i++){
    memset(malloc(10 * ONE_MB), 0, 10 * ONE_MB);
    getrusage(RUSAGE_SELF, &usage);
    printf("%ld\n", usage.ru_maxrss);
    sleep(1);
  }
  return 0;
}
