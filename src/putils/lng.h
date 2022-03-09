
# ifndef _PUTILS_LNG_
# define _PUTILS_LNG_

# include <stdio.h>
# include "str-cpy.h"
# include "dic.h"

# ifndef PATH_SIZE
# define PATH_SIZE 1024
# endif

extern str lng_get (vec * lang_directory, str key);
extern vec * lng_load (str path, str rescue, u16 size);

# endif // _PUTILS_LNG_

