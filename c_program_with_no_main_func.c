/* 
This program intends to run without main function

Have you ever tried writting a c program without main function, Please look at the code

for understanding i would suggest to verify program object file using objdump utility.

compare this program with program using main fucntion by using objdump, you will understand the difference

-------> objdump -d <objfile>

compile the program using:
-------> gcc -nostartfiles c_program_with_no_main_func.c -o c_program_with_no_main_func 
*/

#include<stdio.h>
#include<stdlib.h>

void _start(){
	message();
	exit(0);
}

void message(){
	printf("Hello codedig\n");
}
