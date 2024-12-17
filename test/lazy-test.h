#include <lazy.h>

void test_io_funcs() {
    io().puts("Hello, World!\n");
    char *input;
    io().read(input);
}

void test_math_funcs() {
    print(math().pow(5, 5));
    print(math().fact(5));
}

void test_sys_funcs() {
    sys().cmd("touch lazy-test-output.txt");
}
