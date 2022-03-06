# include "extra.h"

str str_cpy_ (str string, u16 max, str strings [], u16 n_strings) {
	str start = string;
	
	for (u16 i = 0, size = 1; i < n_strings; i++, string--) {
		for (; size < max and (*string++ = *strings [i]++); size++);
	}
	
	*++string = 0;
	return start;
}

str str_cat_ (str string, u16 max, str strings [], u16 n_strings) {
	str end = string;
	u16 size = 1;
	
	for (; *end and size < max; size++, end++);
	
	for (u16 i = 0; i < n_strings; i++, end--) {
		for (; size < max and (*end++ = *strings [i]++); size++);
	}
	
	return string;
}

