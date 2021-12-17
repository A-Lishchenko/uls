#include "../inc/uls.h"

void print_tab (char **files, int size, bool *flags) {
    struct winsize w;
    struct stat buf;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
    int size_of_terminal = w.ws_col;
    int tab_length = 8;
    int max_size = 0;
    for (int i = 0; i < size; i++) {
        if (max_size < mx_strlen(get_name(files[i]))) 
            max_size = mx_strlen(get_name(files[i]));
    }
    if (flags[fl_i]) max_size += 7;
    max_size += tab_length - (max_size % tab_length);
    int cols = size_of_terminal / max_size;
    int rows = size / cols + (size % cols == 0 ? 0 : 1);
    char ***tab_matrix = malloc(sizeof(char**) * rows);
    int k = 0;
    for (int i = 0; i < rows; i++) {
        tab_matrix[i] = malloc(sizeof(char*) * cols);
    }
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (k < size) {
                tab_matrix[i][j] = mx_strdup(files[k]);
                k++;
            }
            else tab_matrix[i][j] = NULL;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (tab_matrix[i][j] != NULL) {
                lstat(tab_matrix[i][j], &buf);
                if (flags[fl_i]) {
                    mx_printint(buf.st_ino);
                    mx_printchar(' ');
                }
                if(flags[fl_G] && isatty(fileno(stdout))) { //colorful output
                    color_print(get_name(tab_matrix[i][j]));
                }
                else {
                    mx_printstr(get_name(tab_matrix[i][j]));
                }
                int temp = max_size - mx_strlen(get_name(tab_matrix[i][j]));
                if (flags[fl_i]) temp -= 7;
                if (j != cols - 1 && tab_matrix[i][j + 1] != NULL) {
                    while (temp > 0) {
                        mx_printchar('\t');
                        temp -= tab_length;
                    }   
                }           
            }
        }
        mx_printchar('\n');
    }
}


