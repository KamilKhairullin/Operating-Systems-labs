#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
if(fork() == 0){
long n = (long)getpid();
printf("Hello from child PID[%ld]\n", n);
}
else{
long n = (long)getpid();
printf("Hello from parent PID[%ld]\n", n);
}
return 0;
}


/*
Every process copies from previous one.

Example:
1
Hello from parent PID[2794]
Hello from child PID[2795]
2
Hello from parent PID[2796]
Hello from child PID[2797]

...
*/
