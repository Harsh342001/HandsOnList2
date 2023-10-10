#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	char buf[100];
	int p  = pipe(fd);
	printf("pipe call output = %d \n" , p);
	int w = write(fd[1] , "Hey! its HandsOn14\n", 20);
	if(w == -1){
		perror("couldn't perform write");
		return -1;
	}
	int r = read(fd[0] ,buf, w);
	if(r == -1){
		perror("couldn't perform read operation");
		return -1;
	}
	printf("content read from pipe is : %s",buf);
	
}
