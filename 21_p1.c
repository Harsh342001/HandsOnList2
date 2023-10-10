#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
int main(){
	int mkfifo = mknod("fifo_21" , S_IFIFO | 0666,0);
	if(mkfifo == -1){
		perror("couldn't creat FIFO file");
	}

	int fd  = open("fifo_21" , O_RDWR);		
	if(fd == -1){
		perror("Error occured while openning file");
		return -1;
	}
	
	char buf[100];
	printf("Enter the data you wanna send to otehr process : \n");
	scanf("%[^\n]" , buf);

	int w = write(fd , &buf , sizeof(buf));
	if(w == -1){
		perror("couldn't perform write operation");	
		return -1;
	}

	int r = read(fd, &buf, sizeof(buf));
	if(r==-1){
		perror("couldn't perform read");
		return -1;
	}
	printf("The data read from other process is : %s \n",buf);
	
	

}