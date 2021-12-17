#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    int left = 0, right = size - 1;
    while (left <= right) {
        int m = (left + right) / 2;
        if (mx_strcmp(arr[m], s) < 0) {
            left = m + 1;
            *count += 1;
        } else if (mx_strcmp(arr[m], s) > 0) {
            right = m - 1;
            *count += 1;
        }
        else {
            *count += 1;
            return m;
        }
    }
    *count = 0;
    return -1;
}



