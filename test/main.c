#include <lazy.h>

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "lazy-test.h"

int main(flagargs) {
    char *debug[] = {"--debug", "-d"};
    char *hello[] = {"--say-hello", "-s"};
    flagzone {
        flag(debug) {
            println("Debug mode activated!");
        }
        flag(hello) {
            println("Hello World!");
        }
    }

	test_comparison_macros();
	test_len_macro();
	test_foreach_forthese_macros();
	test_conditional_macros();
	test_try_catch_macros();
	test_print_macros();
    test_math_macros();
    test_python_macros();
    test_assert_macro();
    test_io_macros();

    return 0;
}
