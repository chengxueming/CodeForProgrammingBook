#include <stdio.h>
# include <endian.h>
#include <stdlib.h>
#include <unistd.h> 
#define memrev32ifbe(p) ((void)(0))
#define panic(...) printf(__VA_ARGS__),_exit(1)

int main(int argc, char const *argv[])
{
    if (__BYTE_ORDER == __LITTLE_ENDIAN) {
        printf("little end\n");
    }
    int a = 1;
    // gcc -E m.cpp -o m.i
    memrev32ifbe(&a);
    panic("%s %d\n", "some wrong", 1);
    printf("no more");
    return 0;
}
