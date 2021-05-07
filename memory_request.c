/*
This Program is intended to know the memory allocation for a process by operating system using malloc/calloc functions. 

Suggestion: Try requesting more than available physical memory, see what happens to your program and allocate a virtual memory/paging/swap space and try to request more than available physical memory and see that program gets extra memory from swap space

*/
#include<stdio.h>
#include<stdlib.h>

#define K 1024
#define M K*K
#define G M*K

void main(){
//Asking for 1GB memory to OS
int *ptr = (int*)malloc(G);
int i;
//Accesing the 1GB memory allocated to ptr
for(i=0;i<(G/4);i++){
ptr[i] = 1;
}
//used sleep to monitor the memory usage from top/htop command while program in use
sleep(5);
free(ptr);
}
