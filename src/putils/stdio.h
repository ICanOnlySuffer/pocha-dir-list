# ifndef _PUTILS_STDIO_
# define _PUTILS_STDIO_

# include <stdio.h>
# include "types.h"

nil print_ (u16 size, str strings []) {
	for (u16 i = 0; i < size; i++) {
		printf (strings [i]);
	}
}

# define print(...)                                     \
	print_ (                                            \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# endif // _PUTILS_STDIO_

