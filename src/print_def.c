#include "../inc/uls.h"

void print_default(char **arr, char *delim, bool *flags) {
    struct winsize w;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
    int size = 0;
    struct stat buf;
    while(*arr != NULL) {
        lstat(*arr, &buf);
        if (flags[fl_m]) {
            size += mx_strlen(get_name(*arr)) + 2;
            if (flags[fl_i]) size += 7;
            if (size >= w.ws_col && *arr) {
                mx_printchar('\n');
                size = mx_strlen(get_name(*arr)) + 2;
                if (flags[fl_i]) size += 7;
                //if(!isatty(fileno(stdout))) size -= 1;
            }
        }
        if (flags[fl_i]) {
            mx_printint(buf.st_ino);
            mx_printchar(' ');
        }
        if(flags[fl_G] && isatty(fileno(stdout))) { //colorful output
            color_print(*arr);
        }
        else {
            mx_printstr(get_name(*arr)); //file name
        }
        arr++;
        if (*arr)
            mx_printstr(delim);
        else mx_printchar('\n');

        
    }
}


