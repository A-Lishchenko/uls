#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if(str == NULL)
        return -1;
    int k = 0;
    int last = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i] != str[i - 1]) {
            if (k == 0)
                k = 2;
            else
                k++;
        }  
        last = i;
    }

    if (str[0] == c)
        k--;
    if (str[last] == c)
        k--;

    return k;
}


