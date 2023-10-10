#include<stdio.h>
#include<unistd.h>

int main(){
	int fd[2];
	int p = pipe(fd);

	if(p == -1){
		perror("Couldn't create pipe");
	}

	if(!fork()){
		// close(1);
		close(fd[0]);
		dup2(fd[1],1);
		execlp("ls", "ls", "-l", (char*) NULL);

	} 

	else{
		// close(0);
		close(fd[1]);
		dup2(fd[0],0);
		execlp("wc", "wc", (char*) NULL);
	}
}