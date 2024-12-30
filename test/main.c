#include <lazy.h>
#include "pretty-test.h"
#include "lazy-test.h"

int main() {
	test_comparison_macros();
	test_len_macro();
	test_foreach_forthese_macros();
	test_memory_macros();
	test_conditional_macros();
	test_try_catch_macros();
	test_print_macros();
    test_math_funcs();

    return 0;
}
