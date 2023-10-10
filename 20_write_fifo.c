#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
int main(){	
	int mkfifo = mknod("fifo_20" , S_IFIFO | 0666,0);
	if(mkfifo == -1){
		perror("couldn't create FIFO file");
	}
	
	int fd  = open("fifo_20" , O_WRONLY);

	if(fd == -1){
		perror("Error occured while openning file");
		return -1;
	}
	char buf[100];
	printf("Enter the data you wanna write : \n");
	scanf("%[^\n]" , buf);

	int w = write(fd , &buf , sizeof(buf));
	if(w == -1){
		perror("couldn't perform write operation");	
		return -1;
	}
}