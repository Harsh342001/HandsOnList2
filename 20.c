#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	// printf("Hello");
	int fd  = open("fifo_20" , O_WRONLY|O_CREAT,0777);		
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