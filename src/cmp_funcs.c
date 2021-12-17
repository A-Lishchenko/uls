#include "../inc/uls.h"

bool t_comp (char *str1, char *str2) {
    struct stat buf;
    lstat(str1, &buf);
    long time1 = buf.st_mtimespec.tv_sec;
    lstat(str2, &buf);
    long time2 = buf.st_mtimespec.tv_sec;
    if(time1 == time2) return def_comp(str1, str2);
    return time1 > time2;
}

bool tc_comp (char *str1, char *str2) {
    struct stat buf;
    lstat(str1, &buf);
    long time1 = buf.st_ctimespec.tv_sec;
    lstat(str2, &buf);
    long time2 = buf.st_ctimespec.tv_sec;
    if(time1 == time2) return def_comp(str1, str2);
    return time1 > time2;
}

bool tu_comp (char *str1, char *str2) {
    struct stat buf;
    lstat(str1, &buf);
    long time1 = buf.st_atimespec.tv_sec;
    lstat(str2, &buf);
    long time2 = buf.st_atimespec.tv_sec;
    if(time1 == time2) return def_comp(str1, str2);
    return time1 > time2;
}

bool S_comp (char *str1, char *str2) {
    struct stat buf;
    lstat(str1, &buf);
    long size1 = buf.st_size;
    lstat(str2, &buf);
    long size2 = buf.st_size;
    if(size1 == size2) return def_comp(str1, str2);
    return size1 > size2;
}

bool def_comp (char *s1, char *s2) {
    while (*s1 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 < *s2;
}

