
# ifndef _PUTILS_VEC_
# define _PUTILS_VEC_

# include <stdlib.h>
# include "cor.h"

typedef struct {
	nil ** items;
	u32 capacity;
	u16 size;
} vec;

extern u32 next_2n (u32 number);
extern vec * vec_new (u32 capacity);

extern nil vec_rsz (vec * vector, u32 capacity);
extern nil vec_psh (vec * vector, nil * item);
extern nil vec_psh_arr (vec * vector, nil * items [], u16 size);
extern nil vec_rmv (vec * vector, u16 index);
extern nil vec_clr (vec * vector);

# define VEC_SRT(vector_, compare_) \
	qsort (vector_ -> items, vector_ -> size, sizeof (nil *), compare_)

# define VEC_LST(vector_) \
	vector_ -> items [vector_ -> size - 1]

# define VEC_FRE(vector_) \
	vec_clr (vector_);    \
	free (vector_)

# endif // _PUTILS_VEC_

