#include "tests.h"
#include "test_1_hessenberg_qr.h"
#include "test_2_hessenberg_qr.h"
#include "test_1_simple_qr.h"

void RunAllTests() {
    Test1SimpleQR();
    Test1HessenbergQR();
    Test2HessenbergQR();
}
