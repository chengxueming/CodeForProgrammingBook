#include <stdio.h>

enum {
    KEYWORD = 01,
    EXTERNAL = 02,
    STATIC = 04,
};

void testBit(int flags) {
    flags &= ~(KEYWORD | EXTERNAL); // 去掉KEYWORD | EXTERNAL
    if((flags & (KEYWORD | EXTERNAL)) == 0) {
        printf("%s\n", "neither keyword nor external");
    }
    flags |= KEYWORD | EXTERNAL; // 加上KEYWORD | EXTERNAL 注意 == 的优先级 比 &高
    if((flags & ~(KEYWORD | EXTERNAL)) == 0) {
        printf("%s\n", "only keyword and external");
    }
    if(flags & KEYWORD || flags & EXTERNAL) {
        printf("%s\n", "is keyword or external");
    }
}

typedef struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} Flags;

void testStruct(Flags flags) {
    printf("%u\n", sizeof(flags));
    //printf("%p\n", &flags.is_static); 无法取地址 不同的机器顺序不一样
    if(flags.is_extern == 0 && flags.is_keyword == 0) {
        printf("struct %s\n", "neither keyword nor external");
    }
    if(flags.is_extern && flags.is_keyword && !flags.is_static) {
        printf("struct %s\n", "only keyword and external");
    }
    if(flags.is_extern || flags.is_keyword) {
        printf("struct %s\n", "is keyword or external");
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    testBit(STATIC | KEYWORD | EXTERNAL);
    testBit(KEYWORD | EXTERNAL);
    Flags flags;
    flags.is_keyword = 1;
    testStruct(flags);
    return 0;
}
