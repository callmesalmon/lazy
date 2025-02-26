#include <lazy.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>

void test_math_macros() {
    assert(min(1, 2) == 1);
    assert(max(1, 2) == 2);

    assert(square(3) == 9);
    assert(cube(3) == 27);
}

void test_assert_macro() {
    massert((5) == (5));
    massert((2+2) != (5));
}

void test_python_macros() {
    assert(not (1 == 2));

    assert(1 == 2 or 2 == 2);
    assert(1 == 1 and 2 == 2);
}

void test_comparison_macros() {
	assert((5 eq 5) == true);
	assert((5 eq 3) == false);
}

void test_len_macro() {
	int arr[] = { 1, 2, 3, 4 };
	char *str = "hello";
	assert(len(arr) == 4);
	assert(len(str) == 5);
}

void test_foreach_forthese_macros() {
	int arr[] = { 1, 2, 3 };
	int sum = 0;
	foreach(item, int, 3, arr) {
		sum += *item;
	}
	assert(sum == 6);

	sum = 0;
	forthese(num, int, 1, 2, 3, 4) {
		sum += num;
	}
	assert(sum == 10);
}

void test_conditional_macros() {
	int x = 5;
	int y = when x > 3 then 10 other 0;
	assert(y == 10);

	y = when x < 3 then 10 other 0;
	assert(y == 0);

	int z = unless x > 3 then 10 other 0;
	assert(z == 0);

	ifnt(x > 3) {
		y = 0;
	} else {
		y = 1;
	}
	assert(y == 1);
}

void test_try_catch_macros() {
	errno = 0;
	try {
        println(NULL);
	}
	catch(EDOM) {
		assert(errno == EDOM);
	}
}

void test_print_macros() {
	print("Testing print macro: ");
	print(123);
	print("\n");
	print("Testing println macro with number: ");
	println(456);
}

void test_io_macros() {
    printfln("Testing printfln macro:");
    printfln("%d", 789);

    /* This part is a *bit* buggy. */
    char *msg;
    input("testing input macro: ", msg);
    printfln("You entered: %s", msg);
}
