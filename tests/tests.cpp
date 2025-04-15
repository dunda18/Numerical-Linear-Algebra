#include "tests.h"
#include "test_1_hessenberg_qr.h"
#include "test_2_hessenberg_qr.h"
#include "test_1_simple_qr.h"
#include "test_1_rayleigh_qr.h"
#include "test_2_rayleigh_qr.h"

namespace NLA {
void RunAllTests() {
    Test1SimpleQR();
    Test1HessenbergQR();
    Test2HessenbergQR();
    Test1RayleighQR();
    Test2RayleighQR();
}
} // namespace NLA
