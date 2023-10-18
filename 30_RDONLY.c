#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
      key_t key = ftok(".",'e');
        printf("%d\n",key);
        int r = shmget(key, 1024, IPC_CREAT|0744);
        printf("%d\n",r);
        if(r<0){
                perror("Error while creating shared memory: ");
                return 0;
        }


    printf("Shared memory segment created with ID: %d\n", r);

    char* shmaddr = (char *)shmat(r, NULL, SHM_RDONLY);
    if (shmaddr == (char *)(-1)) {
        perror("shared memery attach with O_RDONLY failed");
    } else {

        strcpy(shmaddr, "Attempt to overwrite");
        printf("Data in read-only mode: %s\n", shmaddr);
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(1);
        }
        printf("Detached from read-only shared memory.\n");
    }

    if (shmctl(r, IPC_RMID, NULL) == -1) {
        perror("shmctl IPC_RMID");
        exit(1);
    }

    printf("Shared memory segment removed.\n");

    return 0;
}