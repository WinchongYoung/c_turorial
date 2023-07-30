#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
/**
 * 匿名管道
 */
int main(void)
{
	pid_t pid1;
	int fields[2];
	char buffer[80];
	char s[100];
	char ss[100];
	if(pipe(fields)!=0){
		fprintf(stderr,"Createpipe error:%s\n\a",strerror(errno));
		exit(1);
	}
	if((pid1=fork())<0)printf("fork child error!\n");
	/* 子进程写入数据 */
	if(pid1==0){
		printf("fork child,child is sending a message !\n");
		char s[]="hello!\n";
		write(fields[1],s,sizeof(s));
		exit(0);
	}
	/* 父进程读取数据 */
	else {
		printf("parent read start !\n");
		read(fields[0],buffer,80);
		printf("parent receive the message:%s",buffer);
	}
	exit (0);
}

