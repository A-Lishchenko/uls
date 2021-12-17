#include "../inc/uls.h"

void reverse_arr(char ***arr, int size) {
    char **new_arr = malloc(sizeof(char*) * (size + 1));
    new_arr[size] = NULL;
    for(int i = 0; i < size; i++) {
        new_arr[i] = mx_strdup((*arr)[size - 1 - i]);
    }
    for(int i = 0; i < size; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free(*arr);
    *arr = new_arr;
}

