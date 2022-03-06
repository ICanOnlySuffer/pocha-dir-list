# include <stdlib.h>
# include "extra.h"

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

vec * vec_new (u32 capacity) {
	vec * vector = malloc (sizeof (vec));
	vector -> items = malloc (sizeof (nil *) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	
	return vector;
}

nil vec_resize (vec * vector, u32 capacity) {
	nil ** items = realloc (
		vector -> items, sizeof (nil *) * capacity
	);
	if (items) {
		vector -> items = items;
		vector -> capacity = capacity;
	}
}

nil vec_resize_auto (vec * vector) {
	if (vector -> size and vector -> size == vector -> capacity / 4) {
		vec_resize (vector, vector -> capacity / 2);
	}
}

nil vec_append (vec * vector, nil * item) {
	if (vector -> capacity == vector -> size) {
		vec_resize (vector, vector -> capacity * 2);
	}
	vector -> items [vector -> size++] = item;
}

nil vec_append_array (vec * vector, nil * items [], u16 size) {
	if (vector -> capacity < vector -> size + size) {
		vec_resize (vector, next_2n (vector -> size + size));
	}
	while (vector -> size < size) {
		vector -> items [vector -> size++] = *items++;
	}
}

nil vec_remove_at (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

nil vec_clear (vec * vector) {
	for (u32 i = 0; i < vector -> size; i++) {
		free (vector -> items [i]);
	}
	vector -> size = 0;
}

nil vec_free (vec * vector) {
	vec_clear (vector);
	free (vector -> items);
	vector -> capacity = 0;
}

