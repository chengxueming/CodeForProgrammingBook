#include <stdio.h>

int hash(char* str, int nLength) {
    int hash = 5381;
    for(int i = 0; i < nLength; i++) {
        hash = hash * 33 + str[i];
    }
    return hash;
}

void func(int a) {
    printf("hhh \n");
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("%d", hash("abc", 3));
    func(3);
    return 0;
}
