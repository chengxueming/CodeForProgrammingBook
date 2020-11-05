#include<stdio.h>

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1 -n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, int y) {
    unsigned tmp = ~0 << (p+1-n) ^ ~0 << (p+1);
    return y == 0? (x & ~tmp) : (x | tmp);
}

int main() {
    printf("%d", getbits(28, 4, 3));
    printf("%d", setbits(28, 1, 2, 1));
}