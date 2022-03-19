# include "put.h"

nil fil_put (u64 file, str string) {
	write (file, string, str_len (string));
}


nil fil_put_chr (u64 file, chr character) {
	write (file, &character, 1);
}

nil fil_put_arr (u64 file, u16 length, str strings []) {
	do {
		write (file, *strings, str_len (*strings));
		strings++;
	} while (--length);
}

