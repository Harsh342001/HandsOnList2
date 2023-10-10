#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/select.h>
int main(){
	int fd  = open("fifo_20" , O_RDONLY);		
	if(fd == -1){
		perror("Error occured while openning file");
		return -1;
	}

	fd_set rfds;
	struct timeval tv;
	tv.tv_sec = 3;
	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	if(!select(fd +1, &rfds, NULL, NULL, &tv)){
		printf("No data has been written by other process yet");
	}
	else{
		char buf[100];
		printf("data available now");
		int r = read(fd , &buf , sizeof(buf));
		if(r == -1){
			perror("couldn't perform write operation");	
			return -1;
		}

		printf("the data read from fifo file is : %s" , buf);
	}

	

	
}