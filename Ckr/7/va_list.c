#include <stdarg.h>
#include <stdio.h>

void minprintf(char * fmt, ...) {
    va_list ap;
    int ival;
    double dval;
    char * p, *s;
    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for(s = va_arg(ap, char*); *s; s++) {
                putchar(*s);
            }
            break;
        default:
            break;
        }
    }
    va_end(ap);
}

int main() {
    minprintf("%d %s %f \n", 1, "aa", 12.12);
    return 1;
}