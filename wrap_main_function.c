/* 

This program is tntended to show how we can create a warapper for main function in c
The wrapper function will be resolved at pre processor stage during compilation
*/

#include<stdio.h>
#define decode(s,t,u,m,p,i,n,g) s##t##m##u
#define codedig decode(m,a,n,i,f,e,s,t)

int codedig(){
printf("Hello!, I'm in\n");
return 0;
}
