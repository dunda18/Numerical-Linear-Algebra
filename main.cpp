#include <iostream>

#include "tests/tests.h"
#include "except.h"

int main() {
    try {
        srand(123);
        NLA::RunAllTests();
    } catch (...) {
        Except::React();
    }
    return 0;
}
