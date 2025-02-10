#include <lazy.h>
#include <assert.h>

void test_math_funcs() {
    assert(min(1, 2) == 1);
    assert(max(1, 2) == 2);

    assert(square(3) == 9);
    assert(cube(3) == 27);
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
