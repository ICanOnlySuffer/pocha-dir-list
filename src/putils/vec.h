
# ifndef _PUTILS_VEC_
# define _PUTILS_VEC_

# include <stdlib.h>
# include "inc.h"

typedef struct {
	nil ** items;
	u32 capacity;
	u16 size;
} vec;

extern u32 next_2n (u32 number);
extern vec * vec_new (u32 capacity);

extern nil vec_resize (vec * vector, u32 capacity);
extern nil vec_resize_auto (vec * vector);
extern nil vec_append (vec * vector, nil * item);
extern nil vec_append_array (vec * vector, nil * items [], u16 size);
extern nil vec_remove_at (vec * vector, u16 index);

extern nil vec_clear (vec * vector);
extern nil vec_free (vec * vector);

# define VEC_SORT(vector_, compare_) \
	qsort (vector_ -> items, vector_ -> size, sizeof (nil *), compare_)

# endif // _PUTILS_VEC_

