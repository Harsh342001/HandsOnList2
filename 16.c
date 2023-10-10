#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1[2];
    int fd2[2];
	int p1 = pipe(fd1);
	int p2 = pipe(fd2);

	if(p1  == -1 || p2 == -1){
		perror("Error occured while creating pipes");
		return -1;
	}

	if(!fork()){
		close(fd1[1]);
		close(fd2[0]);
		char bufc[100];
		int r = read(fd1[0], &bufc , sizeof(bufc));

		if(r == -1){
			perror("Error occured while reading data");
		}

		printf("The data read from parent is: %s \n" , bufc);


		printf("enter the data you wanna send to parent : \n");	
		scanf("%[^\n]" , bufc);
		int w = write(fd2[1] , &bufc , sizeof(bufc));
		if(w == -1){
			perror("Couldn't perfrom write from child \n");
		}

	}
	else{
		close(fd1[0]);
		close(fd2[1]);
		char bufp[100];
		printf("Enter the data you wanna send to child : \n");
		scanf("%[^\n]" , bufp);
		int w = write(fd1[1] , &bufp , sizeof(bufp));
		if(w == -1){
			perror("Couldn't perform write ");
			return -1;
		}

		int r = read(fd2[0] , &bufp , sizeof(bufp));
		printf("The data read from child is : %s \n", bufp);
	}
}