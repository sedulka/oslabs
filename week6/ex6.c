#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>

int main() {
    int child_1;
    int file_descriptors[2];
    pipe(file_descriptors);
    if(child_1 = fork()) {
        int child_2 ;
        if(child_2 = fork()) {
            printf("Send pid(%d) to first child(%d)\n", child_2, child_1);
            write(file_descriptors[1], &child_2, sizeof(child_2));
            
            int status = 0;
            waitpid(child_2,&status,WUNTRACED);
            printf("Status: %d\n", status);
        }else {
            while(1) {
                printf("I'm second child\n");
                sleep(1);
            }
        }
    }
    else {
        printf("I'm first child\n");
        int child_2 = 0;
        read(file_descriptors[0], &child_2, sizeof(int));
        printf("Recived pid: %d\n", child_2);
        sleep(10);
        kill(child_2, SIGSTOP);
    }
    return 0;
}

