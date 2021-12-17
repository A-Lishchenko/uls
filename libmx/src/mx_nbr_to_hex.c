#include "../inc/libmx.h"

char* mx_nbr_to_hex(unsigned long nbr){
    unsigned long num = nbr;
    unsigned long l = 0;
    unsigned long r;
    while (nbr != 0) {
        r = nbr % 16;
        nbr /= 16;
        l++;
    }
    if (l == 0)
        return 0;
    char *hex = mx_strnew(l);
    for (int i = l - 1; i >= 0; i--) {
        r = num % 16;
        if (r < 10)
            hex[i] = r + 48;
        else
            hex[i] = r + 32 + 55;

        num /= 16;
    }
    return hex;
}

