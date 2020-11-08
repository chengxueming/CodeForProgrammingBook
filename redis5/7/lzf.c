#include<stdio.h>
# define FRST(p) (((p[0]) << 8) | p[1])
# define HLOG 16
#define HSIZE (1 << (HLOG))
#  define IDX(h) ((( h             >> (3*8 - HLOG)) - h*5) & (HSIZE - 1))
typedef unsigned char u8;
# define NEXT(v,p) (((v) << 8) | p[2])
# define LZF_HSLOT_BIAS ((const u8 *)in_data)
typedef unsigned int LZF_HSLOT;
typedef LZF_HSLOT LZF_STATE[1 << (HLOG)];
#define        MAX_LIT        (1 <<  5)
#define        MAX_OFF        (1 << 13)
#define        MAX_REF        ((1 << 8) + (1 << 3))
# define LZF_HSLOT_BIAS ((const u8 *)in_data)

int main() {
    // char a = 1;
    // int b = a << 8 | 1;
    // printf("%d\n", b);
    u8 arr[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    const u8* ip = arr;
    unsigned int hval = FRST(ip);
    hval = NEXT (hval, ip);
    printf("%d %d %d\n", IDX (hval), HSIZE, hval);
    LZF_STATE htab;
    return 0;
}