#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int msqid;
    key_t key;
    struct msqid_ds msq_info;

    // Replace this key with the key of the message queue you want to modify
    key = ftok(".", 'A');

    // Get the message queue ID
    if ((msqid = msgget(key, 0666)) == -1) {
        perror("Error occured while executing msgget system call");
        return 1;
    }

    // Get the current information of the message queue
    if (msgctl(msqid, IPC_STAT, &msq_info) == -1) {
        perror("Error occured while executing msgctl system call");
        return 1;
    }

    // Modify the permission mode (e.g., change to 0644 for read-write permission for owner and read-only for others)
    msq_info.msg_perm.mode = 0644;

    // Set the new permissions using IPC_SET
    if (msgctl(msqid, IPC_SET, &msq_info) == -1) {
        perror("Error occured while executing msgctl system call");
        return 1;
    }

    printf("Message queue permissions changed successfully.\n");

    return 0;
}
