#include <iostream>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <unistd.h>

bool detectDebugger() {
  if (ptrace(PT_TRACE_ME, 0, 0, 0) < 0) {
    printf("Runs under debugger..\n");
    return true;
  }
  return false;
}

int main() {
  detectDebugger();

  pid_t child = fork();
  if (child > 0) {
    std::cout << "I am parent, child pid = " << child << std::endl;
  } else {
    detectDebugger();
    std::cout << "I am child." << std::endl;
  }
  while (true) {
    sleep(100);
  }
  return 0;
}