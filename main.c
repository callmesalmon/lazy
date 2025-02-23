#include <lazy.h>

#define err(fun, ...)           \
        fun##(__VA_ARGS__) != 0

int cmp(int a, int b) {
    return when (int)(a == b)
        then  0
        other 1;
}

int main() {
}
