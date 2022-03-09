
# ifndef _PUTILS_PUT_
# define _PUTILS_PUT_

# include "inc.h"
# include "str.h"
# include "ioe.h"

extern nil put (str string);
extern nil put_arr (str strings [], u16 n_strings);

# define PUT_ARR(...)                                  \
	put_arr (                                          \
		(str []) {__VA_ARGS__},                        \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str) \
	)

# endif // _PUTILS_PUT_

