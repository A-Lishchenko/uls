#include "../inc/uls.h"

int get_dir_size(const char *path, bool *flags) {
    int size = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if(!dir) {
        perror("error open dir\n");
        exit(0);
    }
    while((entry = readdir(dir)) != NULL) {
        if((flags[fl_A] && mx_strcmp(entry->d_name, ".") != 0 && mx_strcmp(entry->d_name, "..") != 0 ) ||
            flags[fl_a] || entry->d_name[0] != '.')
        size++;
    }
    closedir(dir);
    return size;
}
