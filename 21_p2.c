#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int fd  = open("fifo_21" , O_RDWR);		
	if(fd == -1){
		perror("Error occured while openning file");
		return -1;
	}
	
	char buf[100];

	int r = read(fd, &buf, sizeof(buf));
	if(r==-1){
		perror("couldn't perform read");
		return -1;
	}
	printf("The data read from other process is : %s \n",buf);
	
	
	printf("Enter the data you wanna send to other process : \n");
	scanf("%[^\n]" , buf);

	int w = write(fd , &buf , sizeof(buf));
	if(w == -1){
		perror("couldn't perform write operation");	
		return -1;
	}

}