#include<stdio.h>
struct S {
 
    short b[3];
    char d;
 
} __attribute__ ((aligned (128)));

struct T {
 
    short b[3];
    char d;
 
} __attribute__ ((__packed__));


int main() {
    printf("%d\n", sizeof(struct S));
    printf("%d\n", sizeof(struct T));
    return 1;
}
