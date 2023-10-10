#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd  = open("fifo_20" , O_RDONLY);		
	if(fd == -1){
		perror("Error occured while openning file");
		return -1;
	}

	char buf[100];

	int r = read(fd , &buf , sizeof(buf));
	if(r == -1){
			perror("couldn't perform write operation");	
		return -1;
	}

	printf("the data read from fifo file is : %s" , buf);
}