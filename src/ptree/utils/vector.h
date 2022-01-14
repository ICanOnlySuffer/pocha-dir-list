# include <stdlib.h>
# include "types.h"
# pragma once

ux4 next_power_of_2 (ux4 number) {
	number |= number >> 0b00001;
	number |= number >> 0b00010;
	number |= number >> 0b00100;
	number |= number >> 0b01000;
	number |= number >> 0b10000;
	return number + 1;
}

# define for_index(i_, vector_) \
	for (ux2 i_ = 0; i_ < vector_.size; i_++)

struct vector {
	nil **items;
	ux4 capacity;
	ux2 size;
};

struct vector *vector_new (ux4 capacity) {
	struct vector *vector = malloc (sizeof (struct vector));
	vector->items = malloc (sizeof (nil*) * capacity);
	vector->capacity = capacity;
	vector->size = 0;
	
	return vector;
}

nil vector_resize (struct vector *vector, ux4 capacity) {
	nil *items = realloc (vector->items, sizeof (nil*) * capacity);
	if (items) {
		vector->items = items;
		vector->capacity = capacity;
	}
}

nil vector_resize_auto (struct vector *vector) {
	if (vector->size && vector->size == vector->capacity / 4) {
		vector_resize (vector, vector->capacity / 2);
	}
}

nil vector_append (struct vector *vector, nil *item) {
	if (vector->capacity == vector->size) {
		vector_resize (vector, vector->capacity * 2);
	}
	vector->items [vector->size++] = item;
}

nil vector_append_array (struct vector *vector, ux2 size, nil *items[]) {
	if (vector->capacity < vector->size + size) {
		vector_resize (vector, next_power_of_2 (vector->size + size));
	}
	
	while (vector->size < size) {
		vector->items [vector->size++] = *items++;
	}
}

nil vector_remove_at (struct vector *vector, ux2 index) {
	while (index < vector->size) {
		vector->items [index] = vector->items [index + 1];
		index++;
	}
	
	vector->items [--vector->size] = NIL;
}

nil vector_free (struct vector *vector) {
	for_index (i, (*vector)) {
		free (vector->items[i]);
	}
	free (vector->items);
}

# define vector_last(vector_)                   \
	((vector_.size) ?                           \
		vector_.items [vector_.size - 1] : NULL \
	)

# define vector_first(vector_)   \
	((vector_.size) ?            \
		vector_.items [0] : NULL \
	)

# define vector_sort(vector_, compare_) \
	qsort (vector_.items, vector_.size, sizeof (nil*), compare_)












