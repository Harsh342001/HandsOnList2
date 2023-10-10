#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
int main(){
	key_t key = ftok("." , 'A');
	int msgid = msgget(key , IPC_CREAT);
	printf("key = 0x%0x\t msgid = %d\n ", key , msgid);
}