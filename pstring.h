# include "types.h"
# pragma once

ix1 * pstrcat_ (ix1 * string, ux2 max, ux2 n_strings, ix1 * strings []) {
	ix1 * end = string;
	ux2 size = 1;
	
	for (; *end && size < max; size++, end++);
	
	for (ux2 i = 0; i < n_strings; i++, end--) {
		for (; size < max && (*end++ = *strings [i]++); size++);
	}
	
	return string;
}

# define pstrcat(string_, max_, ...)                    \
	pstrcat_ (                                               \
		string_,                                             \
		max_,                                           \
		sizeof ((char *[]) {__VA_ARGS__}) / sizeof (char *), \
		(char *[]) {__VA_ARGS__}                             \
	)










