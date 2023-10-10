#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main() {
    int msqid;
    struct msqid_ds msq_info;

    // Replace this key with the key of the message queue you want to inspect
    key_t key = ftok(".", 'A');

    // Get the message queue ID
    if ((msqid = msgget(key, 0666)) == -1) {
        perror("msgget");
        return 1;
    }

    // Get message queue information
    if (msgctl(msqid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl");
        return 1;
    }

    // Print message queue information
    printf("Access Permissions: %o\n", msq_info.msg_perm.mode);
    printf("UID: %d, GID: %d\n", msq_info.msg_perm.uid, msq_info.msg_perm.gid);
    printf("Time of Last Message Sent: %s", ctime(&msq_info.msg_stime));
    printf("Time of Last Message Received: %s", ctime(&msq_info.msg_rtime));
    printf("Time of Last Change: %s", ctime(&msq_info.msg_ctime));
    printf("Queue Size: %ld\n", msq_info.msg_qbytes);
    printf("Number of Messages in Queue: %ld\n", msq_info.msg_qnum);
    printf("Maximum Number of Bytes Allowed per Message: %ld\n", msq_info.msg_qbytes);
    printf("PID of msgsnd: %d\n", msq_info.msg_lspid);
    printf("PID of msgrcv: %d\n", msq_info.msg_lrpid);

    return 0;
}
