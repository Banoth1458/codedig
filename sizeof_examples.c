/*

This program intends to show size of differnt data types and also about operator "sizeof" usage


*/


#include<stdio.h>

void main()
{
int a = 1;
double b = 2.2;
float c = 10.1;
char d = 'd';

printf("int a = %d\ndouble b = %.2f\nfloat c = %.2f\nchar d = %c\n",a,b,c,d);
printf("Size of Integer is %ld\n",sizeof(a));
printf("Size of double is %ld\n",sizeof(b));
printf("Size of float is %ld\n",sizeof(c));
printf("Size of character is %ld\n",sizeof(d));
printf("Size of the expression sizeof(%d+%.2f) is %ld\n",a,b,sizeof(a+b));
printf("Size of the expression sizeof(%d+%.2f) is %ld\n",a,c,sizeof(a+c));
printf("Size of the expression sizeof(%d+%c) is %ld\n",a,d,sizeof(a+d));
printf("%ld\n",sizeof(printf("Hello codedig")));
}
