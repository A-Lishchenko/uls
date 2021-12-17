#include "../inc/libmx.h"

char *mx_strtrim(const char *str){
    if(str == NULL)
        return NULL;
    int length = 0, start = -1, end = 0;
    for(int i = 0; i < mx_strlen(str); i++){
        if(!mx_isspace(str[i])){
            start = i;
            break;
        }
    }
    if(start == -1)
        return NULL;
    for(int i = mx_strlen(str) - 1; i >= 0; i--){
        if(!mx_isspace(str[i])){
            end = i;
            break;
        }
    }
    length = (end - start) + 1;
    char *temp = mx_strnew(length);
    str += start;
    temp = mx_strncpy(temp, str, length);
    return temp;
}
