#include <stdio.h>
#include <string.h>
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
    struct sigaction action;
    
    memset(&action, 0, sizeof(action));

    action.sa_handler = handle_func;

    sigaddset(&action.sa_mask, SIGINT);

    action.sa_flags = SA_RESTART;

    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    char str[10];
    scanf("%s", str);

    return 0;
}