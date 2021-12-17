#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
	if (c < 128) {
		char symb[1];
		symb[0] = (c >> 0 & 127) | 0;
		write(1, symb, 1);
	} else if (c < 2048) {
		char symb[2];
		symb[0] = (c >> 6 & 31) | 192;
		symb[1] = (c >> 0 & 63) | 128;
		write(1, symb, 2);
	} else if (c < 65536) {
		char symb[3];
		symb[0] = (c >> 12 & 15) | 224;
		symb[1] = (c >> 6 & 63) | 128;
		symb[2] = (c >> 0 & 63) | 128;
		write(1, symb, 3);
	} else if (c < 1114112) {
		char symb[4];
		symb[0] = (c >> 18 & 7) | 240;
		symb[1] = (c >> 12 & 63) | 128;
		symb[2] = (c >> 6 & 63) | 128;
		symb[3] = (c >> 0 & 63) | 128;
		write(1, symb, 4);
	}
}
