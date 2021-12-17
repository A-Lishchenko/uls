#include "../inc/uls.h"

void convert_size(float *size, int *letter) {
    if(*size < 1000)
        return;
    else {
        *size /= 1024;
        (*letter)++;
        convert_size(size, letter);
    }
}

void print_size_name(int value) {
    if(value == 0) mx_printchar('B');
    else if(value == 1) mx_printchar('K');
    else if(value == 2) mx_printchar('M');
    else if(value == 3) mx_printchar('G');
    else if(value == 4) mx_printchar('P');
    else return;
}
