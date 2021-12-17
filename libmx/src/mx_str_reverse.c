#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    if(s != NULL){
        char *begin, *end;
        begin = s; end = s;
        for (int i = 0; i < mx_strlen(s) - 1; i++)
            end++;
        for (int i = 0; i < mx_strlen(s) / 2; i++) {
            mx_swap_char(end, begin);  
            begin++;
            end--;
        }
    }
}
