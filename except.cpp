#include "except.h"

#include <exception>
#include <iostream>

namespace Except {
void React() {
    try {
        throw;
    } catch (std::exception& e) {
        std::cout << e.what() << '\n';
    } catch (...) {
        std::cout << "Unknown error" << '\n';
    }
}
} // namespace Except
