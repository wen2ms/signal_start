#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void task_func() {
    printf("Executed a task\n");
}

void process_func(int sig) {
    printf("Received the signal %d...\n", sig);

    // Default signal handler
    signal(sig, SIG_DFL);
}

int main() {
    // 2, Interrupt from keyboard
    signal(SIGINT, process_func);
    
    // 15,  Termination request
    signal(SIGTERM, SIG_IGN);

    while (1) {
        task_func();
        sleep(2);
    }   
    
    return 0;
}

