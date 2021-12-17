#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len){
    if((big_len < little_len) || (little_len == 0) || (big_len == 0))
        return NULL;
    else{
        return mx_strstr((char*)big, (char*)little);
    }
}
