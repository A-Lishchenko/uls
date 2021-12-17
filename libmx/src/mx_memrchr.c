#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    for (size_t i = n - 1; i != 0; i--) {
        if(*((unsigned char*)s + i) == (unsigned char)c)
            return (unsigned char*)s + i;
    }
    return NULL;
}
