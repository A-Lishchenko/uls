#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    int begin = -1, end = -1, sign = 0, result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '-') && (mx_isdigit(str[i + 1]) == true)) {
            sign = 1;
            continue;
        }
        if ((mx_isspace(str[i]) == false) && (begin == -1))
            begin = i;
        if ((begin > -1) && (mx_isdigit(str[i]) == false) && (end == -1))
            end = i;
    }

    if (end == -1)
        for (int i = begin; str[i] != '\0'; i++)
            result = 10 * result + (int)str[i] - 48;
    else
        for (int i = begin; i < end; i++)
            result = 10 * result + (int)str[i] - 48;

    return sign == 0 ? result : -1 * result;
}





