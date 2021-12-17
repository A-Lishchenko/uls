#ifndef LS
#define LS

#include "../libmx/inc/libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <limits.h> 
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

enum flags {fl_dog, fl_1, fl_A, fl_a, fl_C, fl_c, fl_G, fl_h, 
            fl_i, fl_l, fl_m, fl_R, fl_r, fl_S, fl_T, fl_t, fl_u, 
            fl_o, fl_n, fl_f};

#define FLAG_SIZE 20
#define XATTR_SIZE 10000
#define USAGE "usage: uls [-ACGRSTacfhilmnortu1@] [file ...]\n"
#define RED_COLOR "\x1b[31m"
#define BLUE_COLOR "\x1b[34m"
#define PURPLE_COLOR "\x1b[35m"
#define YELLOW_COLOR "\x1b[33m"
#define RESET_COLOR "\x1b[0m"
 
//print funcs
void print_tab (char **files, int size, bool *flags);
void print_default(char **arr, char *delim, bool *flags);
void detailed_ouput(char **files, int size, bool *flags, bool NeedTotal);
void default_output(char **files, int size, bool *flags, bool total_flag);
void uls_print (int dir_am, bool *flags, char *dirs);
void color_print(char *str);

//init funcs
char **init(int *files_amount, bool *flags, char *path);
void init_args(int argc, char *argv[], char ***files, char ***dirs, int *f_am, int *d_am, bool *flags, bool *error_flag);
bool *init_flags(int argc, char *argv[]);

//sorting
void sort_args(char ***files, int files_amount, bool *flags);
void reverse_arr(char ***arr, int size);
bool t_comp (char *str1, char *str2);
bool tc_comp (char *str1, char *str2);
bool tu_comp (char *str1, char *str2);
bool S_comp (char *str1, char *str2);
bool def_comp (char *s1, char *s2);


//little funcs
void fix_path(char ***arr, char *folder, int size);
void freeding(char **arr);
char* get_name(char *name);
int get_dir_size(const char *path, bool *flags);
int get_args_size(int argc, char *argv[]);
void convert_size(float *size, int *letter);
void print_size_name(int value);

#endif

