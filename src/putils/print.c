# include "extra.h"
# include "str.h"
# include "ioe.h"

nil print (str string) {
	put_str (string, str_len (string));
}

nil print_many_ (str strings [], u08 n_strings) {
	for (u08 i = 0; i < n_strings; i++) {
		print (strings [i]);
	}
}

