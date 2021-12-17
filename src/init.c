#include "../inc/uls.h"

char **init(int *files_amount, bool *flags, char *path) {
    char **files;
    DIR *dir;
    struct dirent *entry;
    int size = get_dir_size(path, flags);
    dir = opendir(path);
    files = malloc(sizeof(char*) * (size + 1));
    files[size] = NULL;
    if(!dir) {
        perror((mx_strjoin("uls: ", path)));
        exit(0);
    }
    while((entry = readdir(dir)) != NULL) {
        if((flags[fl_A] && mx_strcmp(entry->d_name, ".") != 0 && mx_strcmp(entry->d_name, "..") != 0 ) ||
            flags[fl_a] || entry->d_name[0] != '.') {
                if(mx_strcmp(entry->d_name, "uls") != 0) {
                    files[*files_amount] = mx_strdup(entry->d_name);
                    (*files_amount)++;
                }
        }
    }    
    closedir(dir);
    return files;
}

