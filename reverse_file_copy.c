#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

struct args{
int f;
int l;
char *buffer; 
};

void reverse(int i,int j, char *buf){
char t;
while(i!=j){
	t = buf[i];
	buf[i] = buf[j];
	buf[j] = t;
	i++;
	j--;
	}
}

int main(int argc,char **argv){
if(argc<2){
printf("Please required arguments\ni.e ./<exe> <source file> <destination file>\n");
return 0;
}
char *buff = (char*)malloc(10*sizeof(char));
char t;
int f1 = open(argv[1],O_RDONLY);
int f2 = open(argv[2],O_RDWR|O_CREAT);
int i=0,n;
printf("contents of source file is:\n");
while((n=read(f1,&t,1))>0){
	buff[i] = t;
	printf("%c",t);
	++i;
	}

int first=0;

for(i=0;i<strlen(buff);i++){

	if(buff[i]=='\n' || buff[i] == ' '){
	reverse(first,i-1,buff);
	first = i+1;
	}
}

printf("\nreversed of original is \n%s\n",buff);
printf("copied the same to destination file: %s\n",argv[2]);
write(f2,buff,strlen(buff));
close(f1);
close(f2);
}
