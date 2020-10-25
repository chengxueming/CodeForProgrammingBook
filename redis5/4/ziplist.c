#include <stdio.h>
# include <endian.h>

int main(int argc, char const *argv[])
{
    if (__BYTE_ORDER == __LITTLE_ENDIAN) {
        printf("little end\n");
    }
    return 0;
}
