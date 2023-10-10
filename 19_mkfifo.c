#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	
	int mkfifo_val = mkfifo("mkfifo" , 0666);
	if(mkfifo_val == -1){
		perror("couldn't create FIFO file");
	}
}