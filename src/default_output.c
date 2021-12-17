#include "../inc/uls.h"

void default_output(char **files, int size, bool *flags, bool total_flag) {
    if (flags[fl_C]) print_tab(files, size, flags);
    else if (flags[fl_1]) print_default(files, "\n", flags);
    else if (flags[fl_l]) detailed_ouput(files, size, flags, total_flag);
    else if (flags[fl_m]) print_default(files, ", ", flags);
    else if(isatty(fileno(stdout)))
        print_tab(files, size, flags);
    else
        print_default(files, "\n", flags);        
}

