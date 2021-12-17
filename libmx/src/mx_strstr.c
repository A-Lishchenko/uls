#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle){
    char *str_p;
    bool found = false;
    int len = mx_strlen(haystack);
    for (int i = 0; i < len; i++) {
        if(*haystack == *needle){
            str_p = (char*)haystack;
            found = true;
            for(int j = 0; j < mx_strlen(needle); j++){
                if(*haystack != needle[j]){
                    found = false;
                    break;
                }
                haystack++;
            }
        }
        if(found){
                return str_p;
            }
        haystack++;
    }
    return NULL;
}
