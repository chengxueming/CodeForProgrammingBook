#ifndef ZMALLOC
#define ZMALLOC
#include <stdlib.h>
#define zmalloc malloc
#define zfree free
#define zrealloc realloc
#endif // ZMALLOC