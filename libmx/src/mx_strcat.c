#include "../inc/libmx.h"

char *mx_strcat (char *restrict s1, const char *restrict s2) {
    int count = 0;
    char* temp = s1;
    while (*temp != '\0'){
        temp++; count++;
    }
    for(int i = 0; i < mx_strlen(s2); i++) {
        s1[count] = s2[i];
        count++;
    }
    s1[count] = '\0';
    return s1;
}


