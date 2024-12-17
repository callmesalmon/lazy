#include <lazy.h>

int main() {
    io().puts("Welcome to Lazy.h! The library of the future!\n"
              "Hope you're ready for a quick showcase!\n\n");
    io().puts("#1: Printing, I mean, you're seeinf it now!");
    io().puts("#2: Recieve input, please enter your name: ");
    
    char *name;
    io().read(name);
    
    io().puts("Hello, ");
    io().puts(name);
    io().puts("!\n");
    
    io().puts("#3: Math... And counting!\n");
    io().puts("5^5 = ...\n");

    char power = (char)math().pow(5, 5);
    
    io().puts(&power);
    io().puts("!\n");

    char *msg = "Hello World!";

    io().puts("#4: String blablabla, ");
    io().puts(msg);
    io().puts(" becomes ");

    str().strupp(msg);

    io().puts(msg);
    io().puts(" for example!\n");

    io().puts("#5: System calls. This is scary, so I'm going to let\n"
              "you choose, can I create a file called testfile.txt on\n"
              "your beloved computer? [y/N]: ");

    char *perm;
    io().read(perm);

    if (perm != "y") {
        io().puts("\nJumping over to the next part...\n");
        goto next;
    }

    io().puts("\nOK! I'm doing it (using \"touch testfile.txt\")!\n");

    sys().cmd("touch testfile.txt");

next:

    io().puts("Looks like that's all! See you later!\n");
    
    return 0;
}
