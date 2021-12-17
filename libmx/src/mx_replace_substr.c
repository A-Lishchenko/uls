#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	if(str == NULL || sub == NULL || replace == NULL) { 
        return NULL;
    }
	int count_subs = mx_count_substr(str, sub);
	int length = mx_strlen(str) + (count_subs * mx_strlen(replace) - count_subs * mx_strlen(sub));
	char *new_string = mx_strnew(length);
	if(mx_strlen(sub) == 0) return (char*)str;
	else {
		int count = 0;
		for (int i = 0, d_c = 0; i < mx_strlen(str); ++i, ++d_c) {
			if (str[i] == sub[0]) {
				for (int j = i, k = 0; k < mx_strlen(sub); ++j, ++k) {
					if(str[j] != sub[k]) break;
					else count++;
				}
				if (count == mx_strlen(sub)) {
					for (int d = 0; d < mx_strlen(replace); ++d) {
						new_string[d_c] = replace[d];
						d_c++;
					}
					i += mx_strlen(sub)-1;
					d_c--;
					count = 0;
					continue;
				}
			}
			count = 0;
			new_string[d_c] = str[i];
		}
	}
	return new_string;
}

