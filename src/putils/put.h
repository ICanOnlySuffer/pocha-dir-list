
# ifndef _PUTILS_PUT_
# define _PUTILS_PUT_

# include <unistd.h>
# include "str.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

ext nil fil_put (u64 file, str string);
ext nil fil_put_chr (u64 file, chr character);
ext nil fil_put_arr (u64 file, u16 n_strings, str strings []);

# define PUT(string_) \
	fil_put (STD_OUT, string_)

# define PUT_ERR(string_) \
	fil_put (STD_ERR, string_)

# define PUT_CHR(char_) \
	fil_put_chr (STD_OUT, char_)

# define PUT_CHR_ERR(char_) \
	fil_put_chr (STD_ERR, char_)

# define NEW_LNE() \
	PUT_CHR ('\n')

# define NEW_LNE_ERR() \
	PUT_CHR_ERR ('\n')

# define FIL_PUT_ARR(file_, ...)                        \
	fil_put_arr (                                       \
		file_,                                          \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# define PUT_ARR(...) \
	FIL_PUT_ARR (STD_OUT, __VA_ARGS__)

# define PUT_ERR_ARR(...) \
	FIL_PUT_ARR (STD_ERR, __VA_ARGS__)

# endif // _PUTILS_PUT_

