#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void function(int param) {
    printf("Done\n");
    exit(1);
}

int main() {
    signal(SIGINT, function);
    while(1){}
}

