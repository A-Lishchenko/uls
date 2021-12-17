#include "../inc/libmx.h"

int swaps = 0;

int mx_quicksort(char **arr, int left, int right){
    if(arr == NULL)
        return -1;
    if(left >= right)
        return 0;
    int middle = left + (right - left) / 2;
    char *pivot = arr[middle];
    int i = left, j = right;
    do {
        while (mx_strlen(arr[i]) < mx_strlen(pivot)) i++;
        while (mx_strlen(arr[j]) > mx_strlen(pivot)) j--;
        if(i <= j){
            if((i < j) && mx_strlen(arr[i]) != mx_strlen(arr[j])){
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
            }
            i++; j--;
        }
    } while(i <= j);
    if(i < right)
        mx_quicksort(arr, i, right);
    if(left < j)
        mx_quicksort(arr, left, j);
    return swaps;
}
