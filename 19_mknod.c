#include<stdio.h>
#include <sys/stat.h>

int main(){
	
	int mkfifo = mknod("myfifo" , S_IFIFO | 0666,0);
	if(mkfifo == -1){
		perror("couldn't creat FIFO file");
	}
}