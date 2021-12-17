#include "../inc/uls.h"

void color_print(char *str) {
    struct stat buf;
    lstat(str, &buf);
    if(buf.st_mode & S_IFDIR)
        mx_printstr(mx_strjoin(mx_strjoin(BLUE_COLOR, get_name(str)), RESET_COLOR));
    else if(S_ISLNK(buf.st_mode))
        mx_printstr(mx_strjoin(mx_strjoin(PURPLE_COLOR, get_name(str)), RESET_COLOR));
    else if ((buf.st_mode & S_IXUSR) && (buf.st_mode & S_IFREG))
        mx_printstr(mx_strjoin(mx_strjoin(RED_COLOR, get_name(str)), RESET_COLOR));
    else if (buf.st_mode & S_IFIFO)
        mx_printstr(mx_strjoin(mx_strjoin(YELLOW_COLOR, get_name(str)), RESET_COLOR));
    else
        mx_printstr(get_name(str));
}
