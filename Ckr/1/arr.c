#include<stdio.h>
#include<stdlib.h>


typedef struct _SoftArray 
{
    int len;
    int array[1];
} SoftArray;

int main() {
    int dights[26] = {0};
    int c = 0, i = 0;
    while((c = getchar()) != '\n') {
        if(c < 97 || c > 122) {
            printf("other detected");
            return 0;
        }
        dights[c - 97]++;
    }
    for(i;i < 26;i++) {
        printf("%c:%d\n", i + 97, dights[i]);
    }
    printf("eof detected\n");
    int len = 10;
    SoftArray * p = (SoftArray*) malloc(sizeof(SoftArray) + sizeof(int) * len);
    p->array[1] = 12;
    printf("sizeof %d", sizeof(SoftArray));
    return 1;
}