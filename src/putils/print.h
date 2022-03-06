
# ifndef _PUTILS_PRINT_
# define _PUTILS_PRINT_
# include "extra.h"

nil print (str string);
nil print_many_ (str strings [], u08 n_strings);

# define print_many(...)                               \
	print_many_ (                                      \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# endif

