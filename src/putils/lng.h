
# ifndef _PUTILS_LNG_
# define _PUTILS_LNG_

# include <stdio.h>
# include "str.h"
# include "dic.h"

# ifndef PATH_SIZE
# define PATH_SIZE 1024
# endif

ext str lng_get (vec * lang_directory, str key);
ext vec * lng_lod (str path, u16 size);

# endif // _PUTILS_LNG_

