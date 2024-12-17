#include <lazy.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>

void
test_comparison_macros()
{
	assert((5 eq 5) == true);
	assert((5 eq 3) == false);
}

void
test_len_macro()
{
	int arr[] = { 1, 2, 3, 4 };
	char *str = "hello";
	assert(len(arr) == 4);
	assert(len(str) == 5);
}

void
test_foreach_forthese_macros()
{
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

void
test_memory_macros()
{
	int *num = new(int, 42);
	assert(*num == 42);
	delete(num);

	int *arr = vector(3, int, 1, 2, 3);
	assert(arr[0] == 1);
	assert(arr[1] == 2);
	assert(arr[2] == 3);
	delete(arr);
}

void
test_conditional_macros()
{
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

void
test_try_catch_macros()
{
	errno = 0;
	try {
		sqrt(-1);
	}
	catch(EDOM) {
		assert(errno == EDOM);
	}
}

void
test_print_macros()
{
	print("Testing print macro: ");
	print(123);
	print("\n");
	print("Testing println macro with number: ");
	println(456);
}
