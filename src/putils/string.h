# ifndef _PUTILS_STRING_
# define _PUTILS_STRING_

# include <string.h>
# include "types.h"

str pstrcpy_ (str string, u16 max, u16 n_strings, str strings []) {
	str start = string;
	
	for (u16 i = 0, size = 1; i < n_strings; i++, string--) {
		for (; size < max and (*string++ = *strings [i]++); size++);
	}
	
	*++string = 0;
	return start;
}

str pstrcat_ (str string, u16 max, u16 n_strings, str strings []) {
	str end = string;
	u16 size = 1;
	
	for (; *end and size < max; size++, end++);
	
	for (u16 i = 0; i < n_strings; i++, end--) {
		for (; size < max and (*end++ = *strings [i]++); size++);
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

# endif // _PUTILS_STRING_

