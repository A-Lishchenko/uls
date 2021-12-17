#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) return -2;
    char *find = mx_strstr(str, sub);
    if (find == NULL) return -1;
    for (int i = 0; i < mx_strlen(str); i++) {
        if (mx_strcmp(&str[i], find) == 0)
            return i;
    }
    return -1;    
}

