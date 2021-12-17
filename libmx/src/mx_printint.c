#include "../inc/libmx.h"

int it = 0;

void mx_printint(int n){
    if(n == 0 && it == 0){
        mx_printchar('0');
        return;
    }
    else if (n == -2147483648 && it == 0) {
        write(1, "-2147483648", 11);
        return;
    }
    if(n < 0){
        mx_printchar('-');
        n = n * -1;
    }
    int num = -999;
     while (n > 0)  {
        num = n % 10;
        n /= 10;
        it++;
        mx_printint(n);
        break;
    }
    if(num != -999)
        mx_printchar(num + 48);
}

