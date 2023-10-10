#include<stdio.h>
#include<unistd.h>

int main(){
	long pipe_buf , open_max;
	pipe_buf = pathconf("." , _PC_PIPE_BUF);
	open_max = sysconf(_SC_OPEN_MAX);
	printf("pipe buffer = %ld \t  open_max = %ld\n", pipe_buf , open_max);
}