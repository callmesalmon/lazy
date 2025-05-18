/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright (c) 2025 Elis Staaf                                             *
 *                                                                           *
 * Licensed under the Apache License, Version 2.0 (the "License");           *
 * you may not use this file except in compliance with the License.          *
 * You may obtain a copy of the License at                                   *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 * Unless required by applicable law or agreed to in writing, software       *
 * distributed under the License is distributed on an "AS IS" BASIS,         *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
 * See the License for the specific language governing permissions and       *
 * limitations under the License.                                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef __LAZY__
#define __LAZY__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iso646.h>
#include <sys/cdefs.h>

/* DISCLAIMER: Some of these are shamelessly stolen from "Pretty C", which
 *             is licensed under the "WTFPL", keep that in mind. Because
 *             it is licensed under the WTFPL, I'm exercising my legal
 *             right to "DO WHAT THE FUCK I WANT TO". Thankyou. Just
 *             keep in mind that if you see a section with the
 *             "<pretty>" tag it was either blatanly stolen or 
 *             derives from the "Pretty C" module for C. Check
 *             Pretty C out at <github.com/aartaka/pretty.c>. */

/* Debug <pre>,
 *
 * if you want to enable lazy's
 * debug mode, simply type
 *
 * #define LAZY_DEBUG
 *
 * into your program. This
 * enables some important
 * debug messages.
 */
#define DEBUG(...)
#ifndef LAZY_DEBUG
# undef  DEBUG
# define DEBUG(...) \
        printf(__VA_ARGS__);
#endif

/* C++-checks <pre>,
 *
 * #1 can be enabled by defining
 * "LAZY_CPP_ERROR" in your
 * program.
 *
 * #2 can be disabled by
 * defining "LAZY_CPP_NO_WARN"
 * in your program.
 */

#ifdef LAZY_CPP_ERROR
# ifdef __cplusplus
#  error "LAZY ERROR"
#  error "    As LAZY_CPP_ERROR has been defined, lazy.h"
#  error "    has crashed the program you're running."
#  error "    If you want to fix this, consider"
#  error "    undefining LAZY_CPP_ERROR."
# endif
#endif

#ifndef LAZY_CPP_NO_WARN
# ifdef __cplusplus
#  warning "LAZY WARNING"
#  warning "    You are running lazy on C++."
#  warning "    Therefore, some functions will not work."
#  warning "    Define ``LAZY_CPP_NO_WARN`` to hide this message"
# endif
# define LAZY_CPP_NO_WARN
#endif

/* "Predicates" <...> <impl> <pretty> */

#define even     0 == 1 &
#define odd      1 == 1 &
#define positive 0 <
#define negative 0 >
#define neutral  0 ==
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

/* Function success/failure <...> <impl> <pretty> */

#define success 0 ==
#define failure 0 !=

/* Standard logic <...> <impl> <pretty> */

#define is    ==
#define isnt  !=
#define isnot !=

/* Bit logic <...> <impl> <pretty> */

#define bitnot ~
#define bitxor ^

/* Advanced logic <...> <impl> */

#define isor(a, b)     ((a)  || (b))
#define isand(a, b)    ((a)  && (b))
#define isnotor(a, b)  (!(a) || !(b))
#define isnotand(a, b) (!(a) && !(b))
#define isornot(a, b)  ((a)  || !(b))
#define isandnot(a, b) ((a)  && !(b))

/* Small macros <...> <impl> <pretty> */

#define divisible(n, ...)  ((__VA_ARGS__ == 0) ? 0 : ((n) % (__VA_ARGS__) == 0))
#define ensure(x, ...)     ((x) ? (x) : (__VA_ARGS__))
#define limit(lo, n, hi)   ((n) < (lo) ? (lo) : (n) > (hi) ? (hi) : (n))
#define clamp(lo, n, hi)   ((n) < (lo) ? (lo) : (n) > (hi) ? (hi) : (n))
#define between(lo, n, hi) ((n) <= (hi) && (n) => (lo))

/* Ternaries & Conditionals <...> <impl> <pretty> */

#define ifnt(...)      if(!(__VA_ARGS__))
#define ifnot(...)     if(!(__VA_ARGS__))
#define elif           else if
#define elseif         else if
#define elifnt(...)    else if(!(__VA_ARGS__))
#define elseifnt(...)  else if(!(__VA_ARGS__))
#define elifnot(...)   else if(!(__VA_ARGS__))
#define elseifnot(...) else if(!(__VA_ARGS__))
#define when
#define unless      !
#define then        ?
#define other       :
#define otherwise   :
#define otherwhen   :
#define only        : NULL

#define but else

/* returnif <...> <impl>,
 *
 * Returns "a" if expression
 * (__VA_ARGS__) is true,
 * else, return b. Basically:
 *
 *     returnif(0, 256, func() == 0);
 *     -> return (func() == 0) ?
 *        0 : 256;
 */
#define returnif(a, b, ...)   \
    return when (__VA_ARGS__) \
        then a                \
        otherwise b           \

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


static void *pretty_allocpy(size_t size, void *contents) {
	char *allocated = (char *)malloc(size);
	memcpy(allocated, contents, size);
	return allocated;
}

#define new(type, ...)                                                  \
        DEBUG("type: %s\n", #type)                                      \
        (type *) pretty_allocpy(sizeof(type), &((type) {__VA_ARGS__}))

/* Btw there is a better implementation, down below,
 * keeping this in for historical purposes. */
#define vector(length, type, ...)                               \
        DEBUG("type: %s\n", #type)                              \
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
#define NOERROR 0
#define NOERR   0

/* Print++ (Better Print) <...> <impl> <pretty> */

#define print(...)                                                      \
        _Generic((__VA_ARGS__),                                         \
                 bool: fputs((bool)(__VA_ARGS__) ? "true" : "false", stdout), \
                 default: printf(                                       \
                         _Generic((__VA_ARGS__),                        \
                                  char*:              "%s",		\
                                  char:               "%c",		\
                                  short:              "%hi",		\
                                  int:                "%i",		\
                                  long:               "%li",		\
                                  float:              "%g",		\
                                  double:             "%g",		\
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
typedef unsigned char* ubytes;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;

/* Boolean <...> <impl> <pretty> */

#if !defined(__cplusplus)

typedef unsigned int bool;

#define true  (bool)1
#define false (bool)0

#endif

/* Len-Macro <...> <impl> <pretty>,
 *
 * What this does is that it basically
 * calculates the length (L) of an array
 * or (under specific conditions)
 * a string. It's a macro with argument
 * ... (annotated as "a") where
 *
 * a = (if (__STDC_VERSION >= 201112L): string|arr,
 *      else: arr)
 *
 * If a = string, we use strlen(a) (S)
 * to get the length of a. If a is an array, we use
 * the clever sizeof(a) / sizeof(a[0]) (Z)
 * trick. Example:
 *
 *     #include <lazy.h>
 *
 *     int main() {
 *         string a = "Hello World!"; // S = 11
 *         println(len(a));           // L = 11
 *
 *         // THE FOLLOWING ONLY WORKS
 *         // IF __STDC_VERSION >= 201112L:
 *
 *         int b[] = {8, 33, 89, 49,
 *                    23, 49, 23}; // Z = 7
 *         println(len(b));        // L = 7
 *     }
 */

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

/* Miscellanous math <math.h,...> <impl> */

#define min(a, b) ((a) > (b) ? (b) : (a)) /* if a > b: b, a */
#define max(a, b) ((a) < (b) ? (b) : (a)) /* if a > b: a, b */

#define square(x) (x * x)     /* x ^ 2, ex: square(3) = 9   */
#define cube(x)   (x * x * x) /* x ^ 3, ex: cube(3)   = 27  */

/* Factorial, calculated using
 *
 *     x! = x * (x-1)!
 *
 * and is calculated using recursion,
 * e.g:
 *
 *     f(n) = { n = 1: n, n * f(n - 1) }
 *
 * So then, for example
 *
 *     f(5) = 5 * f(4) =
 *     5 * 4 * f(3) = ...
 *
 * is how you'd calculate a factorial.
 */
#define f(n)                   \
        when n is 1            \
        then n                 \
        otherwise n * f(n - 1)

/* This is only really put in here for the
 * possibility of infinity. I made a blog
 * post about this form of infinity that
 * can be found at
 *
 *     https://elisstaaf.github.io/ramblings/2025/01/31/infinity.html
 */
double divide(double x, double y) {
    return x / y;
}

/* It all boils down to
 *
 *     x / y for x = 10, y = 0:
 *         x / 0 = undefined ≈ inf
 *
 * Which is annotated in C as
 *
 *     #define inf divide(x, 0)
 *
 * With x being anything, I
 * chose 10 but you don't need
 * to run x=10, you can run x=6
 * or x=100*39 or any other
 * POSITIVE number. Keyword:
 * positive.
 */
#define inf divide(10, 0)


/* Ctrl-key <impl>,
 *
 * Mimics the behaviour of the Ctrl key by using 0x1f as a memory
 * address to shift the last 3 bits to 0. I don't know how
 * it works either! Don't ask me! I am only a human
 * programmer made out of human flesh! I promise!
 */
#define ctrl(k) ((k) & 0x1f)

/* Vector/Dynamic array <...> <impl> */

#define vec_unpack_(v) \
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data)


#define vec_t(T) \
  struct { T *data; int length, capacity; }


#define vec_init(v) \
  memset((v), 0, sizeof(*(v)))


#define vec_deinit(v) \
  ( free((v)->data),  \
    vec_init(v) ) 


#define vec_push(v, val)               \
  ( vec_expand_(vec_unpack_(v)) ? -1 : \
    ((v)->data[(v)->length++] = (val), 0), 0 )


#define vec_pop(v) \
  (v)->data[--(v)->length]


#define vec_splice(v, start, count)            \
  ( vec_splice_(vec_unpack_(v), start, count), \
    (v)->length -= (count) )


#define vec_swapsplice(v, start, count)            \
  ( vec_swapsplice_(vec_unpack_(v), start, count), \
    (v)->length -= (count) )


#define vec_insert(v, idx, val)             \
  ( vec_insert_(vec_unpack_(v), idx) ? -1 : \
    ((v)->data[idx] = (val), 0), (v)->length++, 0 )


#define vec_sort(v, fn) \
  qsort((v)->data, (v)->length, sizeof(*(v)->data), fn)


#define vec_swap(v, idx1, idx2) \
  vec_swap_(vec_unpack_(v), idx1, idx2)


#define vec_truncate(v, len) \
  ((v)->length = (len) < (v)->length ? (len) : (v)->length)


#define vec_clear(v) \
  ((v)->length = 0)


#define vec_first(v) \
  (v)->data[0]


#define vec_last(v) \
  (v)->data[(v)->length - 1]


#define vec_reserve(v, n) \
  vec_reserve_(vec_unpack_(v), n)

 
#define vec_compact(v) \
  vec_compact_(vec_unpack_(v))


#define vec_pusharr(v, arr, count)                                       \
  do {                                                                   \
    int i__, n__ = (count);                                              \
    if (vec_reserve_po2_(vec_unpack_(v), (v)->length + n__) != 0) break; \
    for (i__ = 0; i__ < n__; i__++) {                                    \
      (v)->data[(v)->length++] = (arr)[i__];                             \
    }\
  } while (0)


#define vec_extend(v, v2) \
  vec_pusharr((v), (v2)->data, (v2)->length)


#define vec_find(v, val, idx)                       \
  do {                                              \
    for ((idx) = 0; (idx) < (v)->length; (idx)++) { \
      if ((v)->data[(idx)] == (val)) break;         \
    }                                               \
    if ((idx) == (v)->length) (idx) = -1;           \
  } while (0)


#define vec_remove(v, val)                    \
  do {                                        \
    int idx__;                                \
    vec_find(v, val, idx__);                  \
    if (idx__ != -1) vec_splice(v, idx__, 1); \
  } while (0)


#define vec_reverse(v)                             \
  do {                                             \
    int i__ = (v)->length / 2;                     \
    while (i__--) {                                \
      vec_swap((v), i__, (v)->length - (i__ + 1)); \
    }                                              \
  } while (0)


#define vec_foreach(v, var, iter)                                 \
  if  ( (v)->length > 0 )                                         \
  for ( (iter) = 0;                                               \
        (iter) < (v)->length && (((var) = (v)->data[(iter)]), 1); \
        ++(iter))


#define vec_foreach_rev(v, var, iter)                    \
  if  ( (v)->length > 0 )                                \
  for ( (iter) = (v)->length - 1;                        \
        (iter) >= 0 && (((var) = (v)->data[(iter)]), 1); \
        --(iter))


#define vec_foreach_ptr(v, var, iter)                              \
  if  ( (v)->length > 0 )                                          \
  for ( (iter) = 0;                                                \
        (iter) < (v)->length && (((var) = &(v)->data[(iter)]), 1); \
        ++(iter))


#define vec_foreach_ptr_rev(v, var, iter)                 \
  if  ( (v)->length > 0 )                                 \
  for ( (iter) = (v)->length - 1;                         \
        (iter) >= 0 && (((var) = &(v)->data[(iter)]), 1); \
        --(iter))

/* Functions <...> <impl> */
#define fn       int
#define fun      int
#define func     int
#define def      int
#define defun    int
#define define   int

#define begin {
#define end   }

/* Classic python-esques <...> <impl> */
#ifndef __cplusplus
#define or  ||
#define and &&
#define not !
#endif

/* Lua-function <impl>,
 *
 * This basically just exists for
 * people that want to switch up
 * their coding style. The params
 * are name (n) and __VA_ARGS__
 * (a). "n" is the name of the
 * function while "a" is the
 * arguments, meaning
 *
 *     int n(a) {
 *
 * is the official syntax.
 * An example being
 *
 *     function(print, char *msg)
 *         printf("%s", msg);
 *         return 0;
 *     end
 *     -> int print(char *msg) {
 *            printf("%s", msg);
 *            return 0;
 *        }
 */
#define function(name, ...) \
        int name(__VA_ARGS__) {

/* Enum <Elixir::Enum, ~Cpp::std> <impl> */ 
typedef struct {
    char* key;
    int value;
} KeyValue;

typedef struct {
    KeyValue* pairs;
    int size;
    int capacity;
} Map;

Map* makeMap() {
    Map* m = (Map*)malloc(sizeof(Map));
    m->pairs = NULL;
    m->size = 0;
    m->capacity = 0;
    return m;
}

void setKeyValue(Map* m, const char* key, int value) {
    for (int i = 0; i < m->size; i++) {
        if (strcmp(m->pairs[i].key, key) == 0) {
            m->pairs[i].value = value;
            return;
        }
    }
    
    if (m->size == m->capacity) {
        m->capacity = m->capacity == 0 ? 1 : m->capacity * 2;
        m->pairs = (KeyValue*)realloc(m->pairs, m->capacity * sizeof(KeyValue));
    }
    
    m->pairs[m->size].key = strdup(key);
    m->pairs[m->size].value = value;
    m->size++;
}

int getValue(Map* m, const char* key, int* found) {
    for (int i = 0; i < m->size; i++) {
        if (strcmp(m->pairs[i].key, key) == 0) {
            *found = 1;
            return m->pairs[i].value;
        }
    }
    *found = 0;
    return 0;
}

void deleteKeyValue(Map* m, const char* key) {
    for (int i = 0; i < m->size; i++) {
        if (strcmp(m->pairs[i].key, key) == 0) {
            free(m->pairs[i].key);
            for (int j = i; j < m->size - 1; j++) {
                m->pairs[j] = m->pairs[j + 1];
            }
            m->size--;
            return;
        }
    }
}

void clearMap(Map* m) {
    for (int i = 0; i < m->size; i++) {
        free(m->pairs[i].key);
    }
    free(m->pairs);
    m->pairs = NULL;
    m->size = 0;
    m->capacity = 0;
}

void printMap(Map* m) {
    printf("map: {\n");
    for (int i = 0; i < m->size; i++) {
        printf("    %s : %d", m->pairs[i].key, m->pairs[i].value);
        if (i < m->size - 1) {
            printf("\n");
        }
    }
    printf("\n}\n");
}

typedef struct node {
  int data;
  struct node* next;
} Node;

#define at(start, index)                \
        Node now = start;               \
        for (int i = 0; i < index; i++) \
             now = now->next;           \
        now;

/* Misc-macros <impl> <...> */
#define jmp  goto
#define jump goto

#define nl (uchar)0x0a /* \n */
#define cr (uchar)0x0d /* \r */

#define plen(p) (sizeof(p) / sizeof(*p))
#define alen(a) (sizeof(a) / sizeof(a[0]))

/* Minimal flag parser <...>,
 *
 * It works by defining a "zone"
 * annotated as a "flagzone" in which
 * you define your flags. It is in reality
 * just a for-loop in disguise, e.g:
 *
 *     for (int i = 0; i < argc; i++)
 *
 * Which can then be applied to command-line
 * arguments using ``argv[i]``. The "flagargs"
 * macro works as the parameters for a "main"
 * function in modern c17, e.g "int argc,
 * char **argv", ex.:
 *
 *     int main(flagargs)
 *     -> int main(int argc, char **argv)
 *
 * The flag macro operates as the "flag-checker",
 * it takes in a parameter (annotated as "arr")
 * which is an array where every element is a
 * different annotation of the flag,
 * therefore "flag({...})" is the
 * correct syntax. It is just using
 * !strcmp, but it's cool nonetheless, ex.:
 *
 *     flag({"--debug", "-d"}) {
 *         println("System: Debug mode activated!");
 *     }
 */
#define flagzone for (int i = 0; i < argc; i++)
#define flagargs int argc, char **argv
#define flag(arr)                                \
        for (int j = 0; j < alen(arr); j++)      \
            if (!strcmp(arr[j], argv[i]))        \

/* Micro-Assert <assert.h> <impl>,
 *
 * This works as a macro where
 * expr = any logical expression
 * (ex.: (2+2 == 5)), and asserts
 * that expr is true, e.g:
 *
 *     !(expr) ? err() : NULL
 *
 * If expr is not true, we error out.
 * As this macro can only be called
 * within a function, simply returning
 * a NULL value should do the trick.
 * Example usage being
 *
 *     int main() {
 *         massert((2 + 2) == (5));
 *         return 0;
 *     }
 */
#define massert(expr)                                        \
        when !(expr) then                                    \
            println("ERROR: %s evaluated to false.", #expr)  \
        only

/* I/O macros <impl> */

/* printf(__VA_ARGS__), printf("\n"); */
#define printfln(...)         \
        printf(__VA_ARGS__);  \
        printf("\n");


/* An advanced function that kind of works
 * like the python "input()" function,
 * but this one is better. It firstly
 * prints a prompt (p), where the
 * user enters a message that gets
 * read into a variable (v). It uses
 * scanf(), but automatically decides
 * on the format (ex.: "%s") of the
 * variable, basically:
 *
 *     scanf(_Generic((v), ...), &v)
 *
 * This makes the function much
 * easier to use, as it includes
 * auto type detection. Example being
 *
 *     int num;
 *     input(">", num);
 *     -> printf("%s", ">");
 *        scanf(_Generic((num), ...),
 *              &num);
 */
#define input(prompt, vari)              \
        printf("%s", prompt);            \
        scanf(_Generic((vari),           \
                  char*:         "%s",   \
                  char:          "%c",   \
                  int:           "%d",   \
                  double:        "%d",   \
                  float:         "%f",   \
                  long int:      "%li",  \
                  long long int: "%lli", \
                  default:       "%p"),  \
              &vari)


/* More elegant macros <...> <impl> */

#define nil      NULL
#define readonly const

/* Lambda <...> <impl> <pretty> */

#if defined(__clang_major__)
#define lambda(ret, name, ...) void * name = (void*) ^ ret (__VA_ARGS__)
#elif defined(__GNUC__) || defined(__GNUG__)
#define lambda(ret, name, ...) ret name (__VA_ARGS__)
#elif defined(__cplusplus)
#define lambda(ret, name, ...) auto name = [](__VA_ARGS__)
#endif

/* In macro <impl> */

bool lazy_in(void *thing, size_t thing_size, size_t total_size, void *things) {
	char *char_things = (char*)things;
	for (size_t i = 0; i < total_size; i += thing_size)
		if (!memcmp(thing, char_things + i, thing_size))
			return true;
    return false;
}

#define in(thing, type, ...)                            \
        lazy_in((void*)(type[1]){thing},                \
                  sizeof(type),                         \
                  sizeof((type[]){__VA_ARGS__}),        \
                  (void*)(type[]){__VA_ARGS__})

/* Easier error handling <impl>,
 *
 * much easier error handling. It's
 * so easy that I can explain it with
 * just an example:
 *
 * int cmp(int a, int b) {
 *     return ((a) == (b))
 *         then 0
 *         otherwise 1;
 * }
 *
 * int main() {
 *     err(cmp, 2 + 2, 5) then
 *         goto fail
 *     only
 *
 *     return 0;
 *
 * fail:
 *     return 1;
 * }
 */
#define err(name, ...)    \
    (name##(__VA_ARGS__)  \
        isnot 0)

/* Arrays <...>,
 *
 * Why did I make this? Well, it's
 * prettier? Like, just look at it:
 *
 * arr(int, li, 1, 2, 3, 4, 5)
 * -> int li[] = {1, 2, 3, 4, 5}
 *
 * Though, my preferred syntax is
 *
 * arr(int, li,
 * 1, 2, 3, 4, 5)
 */
#define arr(type, name, ...)   type name##[] = {__VA_ARGS__}
#define array(type, name, ...) type name##[] = {__VA_ARGS__}
#define list(type, name, ...)  type name##[] = {__VA_ARGS__}

#endif
