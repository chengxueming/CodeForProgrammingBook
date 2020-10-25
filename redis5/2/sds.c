#include<stdio.h>
#include<stdint.h>

// struct __attribute__ ((__packed__)) sdshdr5 {
//     unsigned char flags; /* 3 lsb of type, and 5 msb of string length */
//     char buf[];
// };

struct sdshdr5 {
    unsigned char flags; /* 3 lsb of type, and 5 msb of string length */
    char buf[];
};

struct __attribute__ ((__packed__)) sdshdr8 {
    uint8_t len; /* used */
    uint8_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};

struct sdshdr32 {
    uint32_t len; /* used */
    uint32_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
};

int main(int argc, char const *argv[])
{
    printf("%u", sizeof(struct sdshdr32));
    return 0;
}
