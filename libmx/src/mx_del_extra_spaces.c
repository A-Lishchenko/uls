#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char* str){
   if (str == NULL)
		return NULL;
	int son = 0;
	bool was_sp = false;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (!mx_isspace(str[i])) {
			son++;
			was_sp = false;
		}
		else if (mx_isspace(str[i]) && was_sp == false) {
			son++;
			was_sp = true;
		}
	}

	if (son < 1)
		return NULL;

	char *str_new = mx_strnew(son);

	if (mx_strlen(str_new) == 1 && mx_isspace(str_new[0])) {
		mx_strdel(&str_new);
		return NULL;
	}
	was_sp = false;
	int ind_new = 0;
	for (int i = 0; i < mx_strlen(str); i++) {
		if (!mx_isspace(str[i]))  {
			str_new[ind_new] = str[i];
			ind_new++;
			was_sp = false;
		}
		else if  (mx_isspace(str[i]) && was_sp == false) {
			str_new[ind_new] = ' ';
			ind_new++;
			was_sp = true;
		}
	}
	str_new = mx_strtrim(str_new);
	return str_new;
    }



