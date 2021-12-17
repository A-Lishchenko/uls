#include "../inc/uls.h"

bool* init_flags(int argc, char *argv[]) {
    bool *flags = malloc(sizeof(bool) * FLAG_SIZE);
    for(int i = 0; i < FLAG_SIZE; i++) {
        flags[i] = false;
    }
    int res;
    while((res = getopt(argc, argv, "@1AaCcfGhilmnoRrSTtu")) != -1) {
        switch (res) {
        case '@':
            flags[fl_dog] = true;
            break;
        case '1':
            flags[fl_C] = false;
            flags[fl_l] = false;
            flags[fl_m] = false;
            flags[fl_1] = true;
            break;
        case 'A':
            flags[fl_A] = true;
            break;
        case 'a':
            flags[fl_a] = true;
            break;
        case 'C':
            flags[fl_1] = false;
            flags[fl_l] = false;
            flags[fl_C] = true;
            break;
        case 'c':
            flags[fl_u] = false;
            flags[fl_c] = true;
            break;
        case 'f':
            flags[fl_f] = true;
            flags[fl_a] = true;
            break;
        case 'G':
            flags[fl_G] = true;
            break;
        case 'h':
            flags[fl_h] = true;
            break;
        case 'i':
            flags[fl_i] = true;
            break;
        case 'l':
            flags[fl_m] = false;
            flags[fl_C] = false;
            flags[fl_1] = false;
            flags[fl_l] = true;
            break;
        case 'm':
            flags[fl_l] = false;
            flags[fl_C] = false;
            flags[fl_1] = false;
            flags[fl_m] = true;
            break;
        case 'n':
            flags[fl_l] = true;
            flags[fl_n] = true;
            break;  
        case 'o':
            flags[fl_o] = true;
            flags[fl_l] = true;
            break;
        case 'R':
            flags[fl_R] = true;
            break;
        case 'r':
            flags[fl_r] = true;
            break;
        case 'S':
            flags[fl_S] = true;
            break;
        case 'T':
            flags[fl_T] = true;
            break;
        case 't':
            flags[fl_t] = true;
            break;
        case 'u':
            flags[fl_c] = false;
            flags[fl_u] = true;
            break;
        case '?':
            mx_printerr(USAGE);
            exit(0);
        }
        if (flags[fl_a] == true) 
            flags[fl_A] = false;

        if (flags[fl_S] == true) 
            flags[fl_t] = false;

        if (flags[fl_m] == true) 
            flags[fl_C] = false;
        if(flags[fl_f]) {
            flags[fl_t] = false;
            flags[fl_S] = false;
            flags[fl_r] = false;
        }
    }
    return flags;
}

