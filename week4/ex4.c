#include <stdio.h>
#define TRUE 1

void read(char *st) {
    gets(st);
}

int main() {
    char st[10];
    while (TRUE) {
        printf("$ ");
        read(st);
        system(st);
    }
}
