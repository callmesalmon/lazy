#include <lazy.h>
#include <assert.h>

void test_math_funcs() {
    assert(factorial(5) != (double)NULL);
    assert(mod(4, 5) != (int)NULL);
    assert(knuth(2, 2, 4) != (uint)NULL);
}
