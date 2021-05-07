/*

This program is intended to experiment with limiting the resources for this program using kernel's systemd utility

Run without limiting:
gcc limit_memory_to_process.c -o limit_memory_to_process 
./limit_memory_to_process

Run with limiting memory (in this example requesting for 1M but limiting the program to 1K:
gcc limit_memory_to_process.c -o limit_memory_to_process
systemd-run --scope -p MemoryLimit=1K ./limit_memory_to_process

Explore ulimit/CGROUPS utilities, which are used to limit the resources
*/

#include<stdio.h>
#include<stdlib.h>


void main(){
//request 1MB of memory 
int *ptr = (int*)malloc(1024*1024);
int i;
//Accessig the allocated memory
for(i=0;i<(1024*1024/4);i++){
ptr[i] = 1;
}
//sleep used just to monitor memory statics from htop
sleep(5);
}
