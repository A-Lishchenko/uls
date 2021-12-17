#include "../inc/libmx.h"

char *mx_strndup(const char *s1, size_t n){
    char* copy = mx_strnew(n);
    mx_strncpy(copy, s1, n);
    return copy;
}
