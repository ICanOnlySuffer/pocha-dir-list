
# ifndef _PUTILS_DIC_
# define _PUTILS_DIC_

# include "str.h"
# include "vec.h"

typedef struct {
	str key;
	nil * value;
} k_v; // key_val

extern k_v * k_v_new (str key, nil * value);
extern str dic_get (vec * dictionary, str key);

# endif // _PUTILS_DIC_

