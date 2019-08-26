#include <iostream>
#include <sys/ptrace.h>
#include "BlockDebugger.h"

static BlockDebugger instance;

BlockDebugger::BlockDebugger() {
    std::cerr << "BlockDebugger()" << std::endl;
    blockDebugger();
}

bool BlockDebugger::blockDebugger() {
    if (ptrace(PT_TRACE_ME, 0, nullptr, nullptr) < 0) {
        std::cerr << "Runs under debugger.." << std::endl;
        return true;
        //abort();
    } else {
        std::cerr << "Not runs under debugger.." << std::endl;
    }
    return false;
}
