
# ifndef _PUTILS_IOE_
# define _PUTILS_IOE_

# include "extra.h"

# define IOE_IPT equ 0
# define IOE_OPT equ 1
# define IOE_ERR equ 2

extern nil get_str (str buffer, u64 length);
extern chr get_chr ();

extern nil put_str (str buffer, u64 length);
extern nil put_chr (chr character);

# endif // _PUTILS_IOE_

