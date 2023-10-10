#include <sys/msg.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
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

	printf("Enter the message text : \n");
	scanf("%s" , msg.mtext); 
	int msg_size = strlen(msg.mtext);

	int send_stat = msgsnd(mqid, &msg, msg_size+1, 0);
	if(send_stat == -1){
		perror("failed in sending message");	
	}

}