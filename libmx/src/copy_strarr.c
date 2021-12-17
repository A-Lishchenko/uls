#include "../inc/libmx.h"

char **copy_strarr(char **arr, const int size) {
    char **new__arr = malloc(sizeof(char*) * (size + 1));
    new__arr[size] = NULL;
    for(int i = 0; i < size; i++) {
        new__arr[i] = mx_strdup(arr[i]);
    }
    return new__arr;
}

