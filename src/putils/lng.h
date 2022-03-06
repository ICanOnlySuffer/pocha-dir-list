
# ifndef _PUTILS_LNG_
# define _PUTILS_LNG_
# include "vec.h"

extern str lng_get (vec * lang_directory, str key);
extern vec * lng_load (str path, str rescue, u16 size);

# endif // _PUTILS_LNG

