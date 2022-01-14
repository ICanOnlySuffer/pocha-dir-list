# include <string.h>
# include "types.h"
# pragma once

str pstrcpy_ (str string, ux2 max, ux2 n_strings, str strings []) {
	str start = string;
	
	for (ux2 i = 0, size = 1; i < n_strings; i++, string--) {
		for (; size < max && (*string++ = *strings [i]++); size++);
	}
	
	*++string = 0;
	return start;
}

str pstrcat_ (str string, ux2 max, ux2 n_strings, str strings []) {
	str end = string;
	ux2 size = 1;
	
	for (; *end && size < max; size++, end++);
	
	for (ux2 i = 0; i < n_strings; i++, end--) {
		for (; size < max && (*end++ = *strings [i]++); size++);
	}
	
	return string;
}


# define streql(string_1_, string_2_) \
	(not strcmp (string_1_, string_2_))

# define pstrcat(string_, max_, ...)                    \
	pstrcat_ (                                          \
		string_,                                        \
		max_,                                           \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# define pstrcpy(string_, max_, ...)                    \
	pstrcpy_ (                                          \
		string_,                                        \
		max_,                                           \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)










