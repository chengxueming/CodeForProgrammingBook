#include "stdio.h"
#include "stdlib.h"

void dumpCrash()
{
    char *pStr = "test_content";
    free(pStr);
}
int main()
{
    dumpCrash();
    return 0;
}
