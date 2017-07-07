#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int x = 0;

void func(int signal) {
    printf("Hello.\n");
    x = 1;
}

int main() {
    signal(SIGINT, func);
    while (1) {
        sleep(1);
        printf("Hello!\n");
        if (x == 1) {
            break;
        }
    }
    return 0;
}