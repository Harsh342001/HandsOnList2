#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int msgqid;

    key_t key = YOUR_KEY;

    // Get the message queue ID using the key
    msgqid = msgget(key, 0);

    if (msgqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Remove the message queue
    if (msgctl(msgqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}
