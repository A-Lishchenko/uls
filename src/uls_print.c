#include "../inc/uls.h"

void uls_print (int dir_am, bool *flags, char *dirs) {
    int dir_cont_am = 0;
    char **dir_contains = init(&dir_cont_am, flags, dirs);
    fix_path(&dir_contains, dirs, dir_cont_am);
    sort_args(&dir_contains, dir_cont_am, flags);
    if(mx_strcmp(dirs, ".") != 0 && dir_am > 1) { 
        mx_printstr(dirs);
        mx_printstr(":\n");
    }
    if(dir_contains[0] == NULL) default_output(dir_contains, dir_cont_am, flags, false);
    else default_output(dir_contains, dir_cont_am, flags, true);
    if (flags[fl_R]) {
        for (int j = 0; j < dir_cont_am; j++) {
            struct stat buf;
            lstat(dir_contains[j], &buf);
            if (buf.st_mode & S_IFDIR && mx_strcmp(get_name(dir_contains[j]), ".") != 0 && mx_strcmp(get_name(dir_contains[j]), "..") != 0) {
                mx_printchar('\n');
                uls_print (++dir_am, flags, dir_contains[j]);
            }
        }
    }
    freeding(dir_contains);
    dir_cont_am = 0;
    
}



