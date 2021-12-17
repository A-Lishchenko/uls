#include "../inc/uls.h"

char* get_name(char *name) {
    char* temp = name;
    while(mx_strchr(temp, '/'))
        temp++;
   return temp;  
}
