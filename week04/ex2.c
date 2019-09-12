#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
for(int i = 0; i < 3; i++){
fork();
}
sleep(5); 
return 0;
}

/*
x5 loop
        │         │                 ├─bash───2*[ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
        │         │                 │               │     │     │     └─ex2
        │         │                 │               │     │     ├─ex2───ex2
        │         │                 │               │     │     └─ex2
        │         │                 │               │     ├─ex2─┬─ex2───ex2
        │         │                 │               │     │     └─ex2
        │         │                 │               │     ├─ex2───ex2
        │         │                 │               │     └─ex2
        │         │                 │               ├─ex2─┬─ex2─┬─ex2───ex2
        │         │                 │               │     │     └─ex2
        │         │                 │               │     ├─ex2───ex2
        │         │                 │               │     └─ex2
        │         │                 │               ├─ex2─┬─ex2───ex2
        │         │                 │               │     └─ex2
        │         │                 │               ├─ex2───ex2
        │         │                 │               └─ex2

x5 loop created 32 processes 
number of processes grows in geometric progression

x3 loop create 2^3 = 8 processes
        │         │                 ├─bash───ex2─┬─ex2─┬─ex2───ex2
        │         │                 │            │     └─ex2
        │         │                 │            ├─ex2───ex2
        │         │                 │            └─ex2


*/
