#include <lazy.h>
#include <assert.h>

void test_math_funcs() {
    assert(factorial(5) != 0);
    assert(mod(4, 5) != 0);
    assert(knuth(2, 2, 4) != 0);
}

void test_python_macros() {
#ifndef __cplusplus
    assert(not 1 == 2);
    assert(1 == 2 or 2 == 2);
    assert(1 == 1 and 2 == 2);
#endif
}

#define test_lua_macros function() do \
    return 256;                       \
end;                                  \

fn test_function_macros() do
    return 0;
end
