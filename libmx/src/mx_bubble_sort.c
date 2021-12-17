#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size, bool (*comp)(char*, char*)){
    bool was_swap = true;
    int swps = 0;
    char* temp;
    while(was_swap){
        was_swap = false;
        for(int i = 1; i < size; i++){
            if(comp(arr[i], arr[i - 1])){
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swps++; was_swap = true;
            }
        }
    }
    return swps;
}




