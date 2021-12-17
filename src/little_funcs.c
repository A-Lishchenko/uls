#include "../inc/uls.h"

void fix_path(char ***arr, char *folder, int size) {
    char **new_arr = malloc(sizeof(char*) * (size + 1));
    new_arr[size] = NULL;
    for(int i = 0; i < size; i++) {
        char *temp = malloc(mx_strlen((*arr)[i]) + mx_strlen(folder) + 2);
        mx_strcpy(temp, folder);
        mx_strcat(temp, "/");
        mx_strcat(temp, (*arr)[i]);
        new_arr[i] = temp;
    }
    for(int i = 0; i < size; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;
    }
    free(*arr);
    *arr = new_arr;
}

void freeding(char **arr) {
    char **temp = arr;
    while(*temp != NULL) {
        free(*temp);
        *temp = NULL;
        temp++;
    }
    free(arr);
    arr = NULL;
}

int get_args_size(int argc, char *argv[]) {
    int size = 0;
    for (int i = 1; i < argc; i++)
        if(argv[i][0] != '-' || size) size++;
    return size;
}
