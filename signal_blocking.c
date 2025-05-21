#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void int_handle_func(int sig) {
    printf("sig = %d\n", sig);

    for (int i = 0; i < 5; ++i) {
        printf("sig_%d = %d\n", sig, i);
        sleep(1);
    }
}

void term_handle_func(int sig) {
    sigset_t set;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    
    sigprocmask(SIG_BLOCK, &set, NULL);

    printf("sig = %d\n", sig);

    for (int i = 0; i < 5; ++i) {
        printf("sig_%d = %d\n", sig, i);
        sleep(1);
    }

    sigprocmask(SIG_UNBLOCK, &set, NULL);
}

int main() {
    signal(SIGTERM, term_handle_func);
    signal(SIGINT, int_handle_func);

    int i = 0;
    while (1) {
        printf("i = %d\n", i++);
        sleep(1);
    }

    return 0;
}