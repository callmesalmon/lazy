#ifndef __LAZY__
#define __LAZY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iso646.h>

/* DISCLAIMER: Some of these are shamelessly stolen from "Pretty C", which
 *             is licensed under the "WTFPL", keep that in mind. Because
 *             it is licensed under the WTFPL, I'm exercising my legal
 *             right to "DO WHAT THE FUCK I WANT TO". Thankyou. Just
 *             keep in mind that if you see a section with the
 *             "<pretty>" tag it was either blatanly stolen or 
 *             derives from the "Pretty C" module for C. Check
 *             Pretty C out at <github.com/aartaka/pretty.c>. */

/* "Predicates" <...> <impl> <pretty> */

#define even     0 == 1 &
#define odd      1 == 1 &
#define positive 0 <
#define negative 0 >
#define zero     0 ==
#define empty    NULL ==
#define null     NULL ==

/* Comparison-Definitions <...> <impl> <pretty> */

#define eq ==
#define ne !=
#define gt >
#define lt <
#define ge >=
#define le <=

/* Ternaries & Conditionals <...> <impl> <pretty> */

#define ifnt(...)   if(!(__VA_ARGS__))
#define ifnot(...)  if(!(__VA_ARGS__))
#define elif        else if
#define elifnt(...) else if(!(__VA_ARGS__))
#define elifnot(...) else if(!(__VA_ARGS__))
#define when
#define unless      !
#define then        ?
#define other       :
#define otherwise   :
#define otherwhen   :
#define only        : NULL

/* Loops & Blocks <...> <impl> <pretty> */

#define until(...)   while(!(__VA_ARGS__))
#define always       while(1)
#define forever      while(1)
#define loop         while(1)
#define indefinitely while(1)
#define never        while(0)
#define comment      while(0)
#define repeat       do
#define done         break
#define finish       break
#define pass         continue

/* Dynamically-Typed Declarations <...> <wrapper> <pretty> */

#if defined(__GNUC__) || defined(__GNUG__)
#define var   __auto_type
#define let   __auto_type
#define local __auto_type
#elif __STDC_VERSION__ > 201710L || defined(__cplusplus)
#define var   auto
#define let   auto
#define local auto
#endif

/* Tracking & Freeing Resources <...> <impl> <pretty> */

#if (__STDC_VERSION__ > 201710L || defined(__GNUC__) || defined(__GNUG__))
#define with(var, close, ...)					\
        for (typeof((__VA_ARGS__)) var = (__VA_ARGS__),         \
                     *pretty_with_flag = (void*) 1;             \
             pretty_with_flag;                                  \
             (close)(var), pretty_with_flag = (void*) 0)
#else
#define with(var, close, ...)					\
        for (void *var = (void*) (__VA_ARGS__),                 \
                     *pretty_with_flag = (void*) 1;             \
             pretty_with_flag;                                  \
             (close)(var), pretty_with_flag = (void*) 0)
#endif

/* Python "range()" <...> <impl> <pretty> */

#define forrangeby(var, type, init, target, by) \
        for (type var = (type)(init);           \
             (((init) >= ((type) target))       \
              ? (var > ((type) target))         \
              : (var < ((type) target)));       \
             (((init) >= ((type) target))       \
              ? (var -= (by))                   \
              : (var += (by))))

#if (__STDC_VERSION__ > 201710L || defined(__GNUC__) || defined(__GNUG__)) && !defined(__clang_major__)
#define forrange(var, init, ...)                                \
        for (typeof((init)+(__VA_ARGS__)) pretty_init = (init), \
                     var = pretty_init,                         \
                     pretty_target = (__VA_ARGS__);             \
             ((pretty_init >= pretty_target)                    \
              ? (var > pretty_target)                           \
              : (var < pretty_target));                         \
             var += ((pretty_init >= pretty_target) ? -1 : +1))
#else
#define forrange(var, init, ...)                                \
        for (int pretty_init = (init),                          \
                     var = pretty_init,                         \
                     pretty_target = (__VA_ARGS__);             \
             var != pretty_target;                              \
             var += ((pretty_init >= pretty_target) ? -1 : +1))
#endif

/* Repeat X Times <...> <impl> <pretty> */

#if  (__STDC_VERSION__ > 201710L || defined(__GNUC__) || defined(__GNUG__)) && !defined(__clang_major__)
#define fortimes(var, ...)                                              \
        for (typeof((__VA_ARGS__)) pretty_result = (__VA_ARGS__),       \
                     var = (typeof((__VA_ARGS__))) 0;                   \
             var < pretty_result;                                       \
             ++var)
#else
#define fortimes(var, ...)                                              \
        for (size_t var = 0, pretty_result = (size_t)(__VA_ARGS__);     \
             var < pretty_result;                                       \
             ++var)
#endif

/* Finally, FOREACH!!! <...> <impl> <pretty> */

#define foreach(var, type, length, ...)                                 \
        for (type *pretty_init = (__VA_ARGS__),                         \
                     *pretty_foreach_flag = (void*) 1;                  \
             pretty_foreach_flag;                                       \
             pretty_foreach_flag = (void*) 0)                           \
                for (size_t pretty_offset = 0;                          \
                     pretty_offset < length;                            \
                     pretty_offset += 1)                                \
                        for (type *var = (pretty_init + pretty_offset), \
                                     *pretty_foreach_flag2 = (void*) 1; \
                             pretty_foreach_flag2;                      \
                             pretty_foreach_flag2 = (void*) 0)

/* Loops over provided args <...> <impl> <pretty> */

#define forthese(var, type, ...)                                        \
        for (type *pretty_init = (type[]){__VA_ARGS__},                 \
                     *pretty_forthese_flag = (void*) 1;                 \
             pretty_forthese_flag;                                      \
             pretty_forthese_flag = (void*) 0)                          \
                for (size_t pretty_offset = 0;                          \
                     pretty_offset < (sizeof((type[]){__VA_ARGS__})     \
                                      / sizeof(type));                  \
                     pretty_offset += 1)                                \
                        for (type var = pretty_init [pretty_offset],    \
                                     *pretty_forthese_flag2 = (void*) 1; \
                             pretty_forthese_flag2;                     \
                             pretty_forthese_flag2 = (void*) 0)

/* Easy Resource & Array Allocation <...> <impl> <pretty> */


static void * pretty_allocpy(size_t size, void *contents) {
	char *allocated = (char *)malloc(size);
	memcpy(allocated, contents, size);
	return allocated;
}

#define new(type, ...)                                                  \
        (type *) pretty_allocpy(sizeof(type), &((type) {__VA_ARGS__}))

#define vector(length, type, ...)                               \
        (type*) pretty_allocpy(sizeof(type) * length,           \
                               (type[length]){__VA_ARGS__})

#define delete free

/* "Defer" From the Best Programming Language 
 * Made This century; Go! <...> <impl> <pretty> */

#define defer(...)                              \
        for (bool pretty_flag = 1;              \
             pretty_flag;                       \
             pretty_flag = 0, (__VA_ARGS__))

/* Try/Catch Blocks <...> <impl> <pretty> */

#define try                                     \
        errno = 0;                              \
        for (bool pretty_flag = 1;              \
             pretty_flag;                       \
             pretty_flag = 0)

static int pretty_err_part_of(int err, size_t length, int *errs) {
	for (size_t i = 0; i < length; ++i)
		if (err == errs[i])
			return 1;
	return 0;
}

#define catch(...)                                              \
        if (pretty_err_part_of                                  \
            (errno,                                             \
             sizeof ((int[]){__VA_ARGS__}) / sizeof(int),       \
             (int[]){__VA_ARGS__}))

/* Print++ (Better Print) <...> <impl> <pretty> */

#define print(...)                                                      \
        _Generic((__VA_ARGS__),                                         \
                 bool: fputs((bool)(__VA_ARGS__) ? "true" : "false", stdout), \
                 default: printf(                                       \
                         _Generic((__VA_ARGS__),                        \
                                  char*:              "%s",		\
                                  char:               "%c",		\
                                  signed char:        "%hhi",		\
                                  short:              "%hi",		\
                                  int:                "%i",		\
                                  long:               "%li",		\
                                  long long:          "%lli",		\
                                  unsigned char:      "%hhu",		\
                                  unsigned short:     "%hi",		\
                                  unsigned int:       "%u",		\
                                  unsigned long:      "%lu",		\
                                  unsigned long long: "%llu",		\
                                  float:              "%g",		\
                                  double:             "%g",		\
                                  long double:        "%Lg",		\
                                  default:            "%p"),		\
                         (__VA_ARGS__)))
#define println(...)				\
	print(__VA_ARGS__), print("\n")

/* Type-Definitions <...> <impl> <pretty> */

typedef char*          string;
typedef char           byte;
typedef char*          bytes;
typedef void*          any;
typedef unsigned char  uchar;
typedef unsigned char  ubyte;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

/* Boolean <...> <impl> <pretty> */

typedef unsigned int bool;

#define true  (bool)1
#define false (bool)0

/* Len-Macro <...> <impl> <pretty> */

#if __STDC_VERSION__ >= 201112L
#define len(...)                                                        \
        (__VA_ARGS__ == NULL) ? 0                                       \
        : _Generic((__VA_ARGS__),                                       \
                   char*: strlen((char*)(__VA_ARGS__)),                 \
                   default: (sizeof(__VA_ARGS__) / sizeof(__VA_ARGS__[0])))
#else
#define len(...)                                                \
        (__VA_ARGS__ == NULL) ? 0                               \
        : (sizeof(__VA_ARGS__) / sizeof(__VA_ARGS__[0]))
#endif


/* IO-Class <stdio.h> <wrapper> */

typedef struct {
    int (*puts)(char *str);
    int (*read)(char *str);
} __io__;

int put(char *str) {
    printf("%s\n", str);
    return 0;
}

int read(char *str) {
    scanf(str);
    return 0;
}

__io__ io() {
    __io__ obj = {
        .puts = &put,
        .read = &read
    };
    return obj;
}

/* Math-Class <math.h...> <impl> */

typedef struct {
    int (*fact)(int n);
    int (*pow)(int n, int k);
    int (*inf)();
} __math__;

int fact(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int lpow(int n, int k) {
  int res = 1;
  while (k > 0)
  {
    res *= n;
    --k;
  }
  return res;
}

int inf() {
    return ~(1<<31);
}

__math__ math() {
    __math__ obj = {
        .fact = &fact,
        .pow  = &lpow,
        .inf  = &inf
    };
    return obj;
}

/* String-Class <str(s).h> <impl> */

typedef struct {
    int  (*strlen)(char* str);
    void (*strcpy)(char* dest, char* src);
    bool (*strcmp)(char* a, char* b);
    void (*stradd)(char* base, char* extension);
    void (*strcls)(char* str);
    char (*char_to_upper)(char character);
    void (*strupp)(char* str);
} __str__;

int lstrlen(char* str) {
    int length = 0;
    while (*str != 0) {
        ++length;
        ++str;
    }
    return length;
}

void lstrcpy(char* dest, char* src) {
    int size = strlen(src) + 1;
    for (int i = 0; i < size; ++i) {
        dest[i] = src[i];
    }
}

bool lstrcmp(char* a, char* b) {
    int i = 0;
    while (1) {
        if (a[i] != b[i]) {
            return false;
        }
        else if (a[i] == 0 && b[i] == 0) {
            return true;
        }
    ++i;
    }
}

void lstradd(char* base, char* extension) {
    strcpy(base + strlen(base), extension);
}

void lstrcls(char* str) {
    while (*str != 0) {
        *str = 0;
        ++str;
    }
}

char lchar_to_upper(char character) {
    char offset = 'A' - 'a';
    if (character >= 'a' && character <= 'z') {
        return character + offset;
    }
    return character;
}

void lstrupp(char* str) {
    while (*str != 0) {
        *str = lchar_to_upper(*str);
        ++str;
    }
}

__str__ str() {
    __str__ obj = {
        .strlen        = &lstrlen,
        .strcpy        = &lstrcpy,
        .strcmp        = &lstrcmp,
        .stradd        = &lstradd,
        .strcls        = &lstrcls,
        .char_to_upper = &lchar_to_upper,
        .strupp        = &lstrupp
    };
    return obj;
}

/* System-Class <stdlib.h?...> <wrapper> */

typedef struct {
    int   (*cmd)(char *self);
} __sys__;

int cmd(char *self) {
    system(self);
    return 0;
}

__sys__ sys() {
    __sys__ obj = {
        .cmd  = &cmd,
    };
    return obj;
}

#endif
