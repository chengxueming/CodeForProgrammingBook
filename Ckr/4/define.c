#include<stdio.h>
#define forever for (;;)
#define max(A, B) ((A) > (B) ? (A) : (B))
// #define paste(front, back) front ## back
#define swap(t,x,y) do { t tmp = x;\
x = y;\
y = tmp; } while (0)

#define BSD 1
#define MSDOS 2
#define SYSTEM BSD

#if !defined(max)
int max(int a, int b) {
    return a > b ? a : b;
}
#endif

#define dprint(expr) printf(#expr " = %s", "expr")
int main() {
    // forever {
    //     printf("hhhhh\n");
    // }
    printf("%d\n", max(1, 2));
    //dprint(2 + 2);
    //dprint("12/5");
    // printf("%s", paste("1","2"));
#if SYSTEM == BSD
    printf("system is bsd\n");
#elif SYSTEM == MSDOS
    printf("system is msdos\n");
#endif
    int a = 1;
    int b = 2;
    swap(int, a, b);
    printf("a: %d, b: %d", a, b);
    return 1;
}