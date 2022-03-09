
# ifndef _PUTILS_DIC_
# define _PUTILS_DIC_

# include "str.h"
# include "vec.h"

typedef struct {
	str key;
	nil * value;
} par;

extern par * par_new (str key, nil * value);
extern str dic_get (vec * dictionary, str key);

# endif // _PUTILS_DIC_

