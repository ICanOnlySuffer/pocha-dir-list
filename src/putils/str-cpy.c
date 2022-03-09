# include "str-cpy.h"

/* Notes:
 *   - might need to be converted to x86 assembly and added to str.asm
 */

str str_cpy (str string, u16 max, str strings [], u16 n_strings) {
	str start = string;
	
	for (u16 i = 0, size = 1; i < n_strings; i++, string--) {
		while (size < max and (*string++ = *strings [i]++)) {
			size++;
		}
	}
	
	*++string = 0;
	return start;
}

str str_cat (str string, u16 max, str strings [], u16 n_strings) {
	str end = string;
	u16 size = 1;
	
	while (*end and size < max) {
		size++;
		end++;
	}
	
	for (u16 i = 0; i < n_strings; i++, end--) {
		while (size < max and (*end++ = *strings [i]++)) {
			size++;
		}
	}
	
	return string;
}

