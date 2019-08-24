#include <iostream>
#include <sys/ptrace.h>

bool detectDebugger() {
  if (ptrace(PT_TRACE_ME, 0, 0, 0) < 0) {
    printf("Runs under debugger..\n");
    return true;
  }
  return false;
}

int main() {
  detectDebugger();

  std::cout << "Hello, World!" << std::endl;
  return 0;
}