# ifndef _PUTILS_VECTOR_
# define _PUTILS_VECTOR_

# include <stdlib.h>
# include "types.h"

u32 next_2n (u32 number) {
	number |= number >> 0b00001;
	number |= number >> 0b00010;
	number |= number >> 0b00100;
	number |= number >> 0b01000;
	number |= number >> 0b10000;
	return number + 1;
}

typedef struct {
	nil ** items;
	u32 capacity;
	u16 size;
} vec;

vec * vector_new (u32 capacity) {
	vec * vector = malloc (sizeof (vec));
	vector -> items = malloc (sizeof (nil *) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	
	return vector;
}

nil vector_resize (vec * vector, u32 capacity) {
	nil ** items = realloc (
		vector -> items, sizeof (nil *) * capacity
	);
	if (items) {
		vector -> items = items;
		vector -> capacity = capacity;
	}
}

nil vector_resize_auto (vec * vector) {
	if (vector -> size and vector -> size == vector -> capacity / 4) {
		vector_resize (vector, vector -> capacity / 2);
	}
}

nil vector_append (vec * vector, nil * item) {
	if (vector -> capacity == vector -> size) {
		vector_resize (vector, vector -> capacity * 2);
	}
	vector -> items [vector -> size++] = item;
}

nil vector_append_array (vec * vector, u16 size, nil * items[]) {
	if (vector -> capacity < vector -> size + size) {
		vector_resize (vector, next_2n (vector -> size + size));
	}
	while (vector -> size < size) {
		vector -> items [vector -> size++] = *items++;
	}
}

nil vector_remove_at (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

nil vector_clear (vec * vector) {
	for (u32 i = 0; i < vector -> size; i++) {
		free (vector -> items [i]);
	}
	vector -> size = 0;
}

nil vector_free (vec * vector) {
	vector_clear (vector);
	free (vector -> items);
	vector -> capacity = 0;
}

# define vector_last(vector_) \
	((vector_ -> size) ? vector_ -> items [vector_ -> size - 1] : NIL)

# define vector_first(vector_) \
	((vector_ -> size) ? vector_ -> items [0] : NIL)

# define vector_sort(vector_, compare_)                             \
	qsort (                                                         \
		vector_ -> items, vector_ -> size, sizeof (nil *), compare_ \
	)

# endif // _PUTILS_VECTOR_

