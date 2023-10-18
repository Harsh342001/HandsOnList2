#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    int shmid; 
    key_t key = 1234; 

    shmid = shmget(key, 1024, IPC_CREAT | 0666);

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    printf("Shared memory segment created with ID: %d\n", shmid);

    char *shmaddr = (char *)shmat(shmid, NULL, 0);

    if (shmaddr == (char *)(-1)) {
        perror("Error attaching shared memory address ");
        exit(1);
    }

    char data[] = "Hello, shared memory!";
    strcpy(shmaddr, data);
    printf("Data written to shared memory: %s\n", shmaddr);

   
    if (shmdt(shmaddr) == -1) {
        perror("shmdt");
        exit(1);
    }

    printf("Detached from shared memory.\n");

    
    return 0;
}
