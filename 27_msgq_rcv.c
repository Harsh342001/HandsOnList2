#include <sys/msg.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	struct msgbuf {
               long mtype;       /* message type, must be > 0 */
               char mtext[100];    /* message data */
           } msg;

	key_t key = ftok("." , 'A');
	int mqid = msgget(key , IPC_CREAT);
	printf("key = 0x%0x\t messageQueueid = %d\n ", key , mqid);

	printf("Enter message type : ");
	scanf("%ld" , &msg.mtype);

	int msg_size = strlen(msg.mtext);

	printf("enter 0 for setting flag in msgrcv as 0 and 1 for IPC_NOWAIT");
	int msgflag;
	scanf("%d" , &msgflag); 
	int ret = msgrcv(mqid, &msg, sizeof(msg.mtext), msg.mtype, msgflag);

	if(ret == -1){
		perror("failed in retrieving message");
		exit(-1);
	}

	printf("message retrieved from message queue is : %s" , msg.mtext);

}