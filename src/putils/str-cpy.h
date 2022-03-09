
# ifndef _PUTILS_STR_CPY_
# define _PUTILS_STR_CPY_

# include "inc.h"

extern str str_cpy (str string, u16 max, str strings [], u16 n_strings);
extern str str_cat (str string, u16 max, str strings [], u16 n_strings);

# define STR_CAT(string_, max_, ...)                   \
	str_cat (                                          \
		string_,                                       \
		max_,                                          \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# define STR_CPY(string_, max_, ...)                   \
	str_cpy (                                          \
		string_,                                       \
		max_,                                          \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# endif // _PUTILS_STR_CPY_

