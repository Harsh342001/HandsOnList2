#include<stdio.h>
#include<unistd.h>

int main(){
	int fd1[2];
	int fd2[2];
	int p1 = pipe(fd1);
	int p2 = pipe(fd2);

	if(p1 == -1 || p2 == -1){
		perror("Couldn't create pipes");
	}

	if(!fork()){
		// close(1);
		close(fd1[0]);
		dup2(fd1[1],1);
		execlp("ls", "ls", "-l", (char*) NULL);

	} 

	else{
		if(!fork){
			close(fd1[1]);
			close(fd2[0]);
			dup2(fd1[0],0);
			dup2(fd2[1],1);
			execlp("grep", "grep","^d" , (char*) NULL);
		}
		// close(0);
		else{
			close(fd2[1]);
			dup2(fd2[0],0);
			execlp("wc", "wc", (char*) NULL);
		}
		
	}
}
