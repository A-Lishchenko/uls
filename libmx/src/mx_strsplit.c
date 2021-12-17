#include "../inc/libmx.h"

int count(const char *str, char c) {
	int k = 0;
	while (str[k] != c && str[k])
		k++;
	return k;
}

char **mx_strsplit(const char *s, char c) {
    int wlen = 0;
    int i = 0;
    char **new_str = NULL;

    if (!s)
        return NULL;
    new_str = (char **)malloc((count(s, c) + 1) * sizeof(char *));
    while ((*s) && (*s != '\0')) {
        if (*s != c) {
            wlen = count(s, c);
            new_str[i] = mx_strndup(s, wlen);
            s += wlen;
            i++;
            continue;
        }
        s++;
    }
    new_str[i] = NULL;
    return new_str;
}
