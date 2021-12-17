#include "../inc/uls.h"

void sort_args(char ***files, int files_amount, bool *flags) {
    if(flags[fl_S]) mx_bubble_sort(*files, files_amount, S_comp);
    else {
        if (flags[fl_t]) {
            if (flags[fl_c]) mx_bubble_sort(*files, files_amount, tc_comp);
            else if (flags[fl_u]) mx_bubble_sort(*files, files_amount, tu_comp);
            else mx_bubble_sort(*files, files_amount, t_comp);
        }
        else mx_bubble_sort(*files, files_amount, def_comp);
    }
    if (flags[fl_r]) reverse_arr(files, files_amount);
}

