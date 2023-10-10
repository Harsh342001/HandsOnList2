#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];

	int p = pipe(fd);

	if(p  == -1){
		perror("Error occured while creating pipe");
	}

	if(!fork()){
		close(fd[1]);
		char bufc[100];
		int r = read(fd[0], &bufc , sizeof(bufc));

		if(r == -1){
			perror("Error occured while reading data");
		}

		printf("The data read from parent is: %s \n" , bufc);

	}
	else{
		close(fd[0]);
		char bufp[100];
		printf("Enter the data you wanna send to child \n");
		scanf("%[^\n]" , bufp);
		int w = write(fd[1] , &bufp , sizeof(bufp));
		if(w == -1){
			perror("Couldn't perform write ");
			return -1;
		}
	}
}