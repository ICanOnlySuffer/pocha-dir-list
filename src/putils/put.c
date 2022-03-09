# include "put.h"

nil put (str string) {
	put_str (STD_OUT, string, str_len (string));
}

nil put_arr (str strings [], u16 n_strings) {
	for (u16 i = 0; i < n_strings; i++) {
		put (strings [i]);
	}
}

