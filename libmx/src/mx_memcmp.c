#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n){
    return mx_strncmp((char*)s1, (char*)s2, n);
}

