#include "../inc/libmx.h"

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 != NULL && s2 != NULL) {
        char *s3 = mx_strnew(mx_strlen(s1) + mx_strlen(s2) - 1);
        s3 = mx_strcat(s3, s1);
        s3 = mx_strcat(s3, s2);
        return s3;
    }
    else if (s1 == NULL && s2 != NULL){
        char *s3 = mx_strnew(mx_strlen(s2));
        s3 = mx_strcat(s3, s2);
        return s3;
    }
    else if (s1 != NULL && s2 == NULL) {
        char *s3 = mx_strnew(mx_strlen(s1));
        s3 = mx_strcat(s3, s1);
        return s3;
    }
    else
        return NULL;
}


