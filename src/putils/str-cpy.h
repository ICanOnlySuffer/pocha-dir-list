
# ifndef _PUTILS_STR_CPY_
# define _PUTILS_STR_CPY_
# include "extra.h"

extern str str_cpy_ (str string, u16 max, str strings [], u16 n_strings);
extern str str_cat_ (str string, u16 max, str strings [], u16 n_strings);

# define str_cat(string_, max_, ...)                   \
	str_cat_ (                                         \
		string_,                                       \
		max_,                                          \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# define str_cpy(string_, max_, ...)                   \
	str_cpy_ (                                         \
		string_,                                       \
		max_,                                          \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# endif // _PUTILS_STR_CPY_

