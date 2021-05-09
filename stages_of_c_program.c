/*
This program intends to show various stages of compilation of a c program using gcc compiler

Pre-processor (.i) ------> compiler (.s) --------> assembler (.o) -------> linker (executable)

Use the command to get all of this files generated for this program.

----command----
gcc --save-temps stages_of_c_program.c -o stages_of_c_program

*/

#include<stdio.h>

#define code 1234

int main(){
	printf("Hello codedig %d\n",code);
	return 0;
}
