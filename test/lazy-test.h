#include <lazy.h>
#include <assert.h>

void test_math_funcs() {
    assert(factorial(5) != 0);
    assert(mod(4, 5) != 0);
    assert(knuth(2, 2, 4) != 0);
}
