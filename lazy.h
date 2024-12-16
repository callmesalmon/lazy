#include <stdio.h>

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

int pow(int n, int k) {
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
        .pow  = &pow,
        .inf  = &inf
    };
    return obj;
}

/* String-Class <string(s).h> <impl> */

typedef struct {
    int  (*strlen)(char* string);
    void (*strcpy)(char* dest, char* src);
    bool (*strcmp)(char* a, char* b);
    void (*stradd)(char* base, char* extension);
    void (*strcls)(char* string);
    char (*char_to_upper)(char character);
    void (*strupp)(char* string);
} __str__;

int strlen(char* string)
{
  int length = 0;
  while (*string != 0)
  {
    ++length;
    ++string;
  }
  return length;
}

void strcpy(char* dest, char* src)
{
  int size = strlen(src) + 1;
  for (int i = 0; i < size; ++i)
  {
    dest[i] = src[i];
  }
}

bool strcmp(char* a, char* b)
{
  int i = 0;
  while (1)
  {
    if (a[i] != b[i])
    {
      return false;
    }
    else if (a[i] == 0 && b[i] == 0)
    {
      return true;
    }
    ++i;
  }
}

void stradd(char* base, char* extension)
{
  strcpy(base + strlen(base), extension);
}

void strcls(char* string)
{
  while (*string != 0)
  {
    *string = 0;
    ++string;
  }
}

char char_to_upper(char character)
{
  char offset = 'A' - 'a';
  if (character >= 'a' && character <= 'z')
  {
    return character + offset;
  }
  return character;
}

void strupp(char* string)
{
  while (*string != 0)
  {
    *string = char_to_upper(*string);
    ++string;
  }
}

__str__ str() {
    __str__ obj = {
        .strlen        = &strlen,
        .strcpy        = &strcpy,
        .strcmp        = &strcmp,
        .stradd        = &stradd,
        .strcls        = &strcls,
        .char_to_upper = &char_to_upper,
        .strupp        = &strupp
    };
    return obj;
}
