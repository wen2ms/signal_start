#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_func(int sig) {
    printf("sig = %d\n", sig);

    for (int i = 0; i < 5; ++i) {
        printf("sig_%d = %d\n", sig, i);
        sleep(1);
    }
}

int main() {
    signal(15, handle_func);
    signal(34, handle_func);

    int i = 0;
    while (1) {
        printf("i = %d\n", i++);
        sleep(1);
    }

    return 0;
}