#include <iostream>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>

bool blockDebugger() {
    if (ptrace(PT_TRACE_ME, 0, 0, 0) < 0) {
        printf("Runs under debugger..\n");
        return true;
        //abort();
    } else {
        printf("Not runs under debugger..\n");
    }
    return false;
}

int main() {
    blockDebugger();

    pid_t child = fork();
    if (child > 0) {
        std::cout << "I am parent, parent pid = " << getpid() << ", child pid = " << child << std::endl;
    } else {
        blockDebugger();
        std::cout << "I am child." << std::endl;
    }

    while (true) {
        sleep(100);
    }
    return 0;
}