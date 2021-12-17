#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    char *csrc = (char*)src;
    char *cdest = (char*)dst;
    char *temp = malloc(sizeof(char) * len);
    for (size_t i = 0; i < len; i++)
       temp[i] = csrc[i];
    for (size_t i = 0; i < len; i++)
       cdest[i] = temp[i];
    free(temp);
    return dst;
}
