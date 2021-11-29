# include <stdlib.h>
# include "types.h"
# pragma once

ux4 next_power_of_2 (ux4 number) {
	number--;
	number |= number >> 0b00001;
	number |= number >> 0b00010;
	number |= number >> 0b00100;
	number |= number >> 0b01000;
	number |= number >> 0b10000;
	return number + 1;
}

# define for_index(i_, vector_) \
	for(ux2 i_ = 0; i_ < vector_.size; i_++)

# define new_vector(type_, fallback_)         \
	{                                         \
		.items = malloc (sizeof (type_) * 4), \
		.capacity = 4,                        \
		.size = 0,                            \
		.fallback = fallback_                 \
	}

# define define_vector(name_, type_)                                           \
	struct name_ {                                                             \
		type_ * items;                                                         \
		ux4 capacity;                                                          \
		ux2 size;                                                              \
		type_ fallback;                                                        \
	};                                                                         \
	                                                                           \
	/* resize */                                                               \
	                                                                           \
	ix0 name_##_resize (struct name_ * vector, ux4 capacity) {                 \
		type_ * items;                                                         \
		items = realloc (vector -> items, sizeof (type_) * capacity);          \
		                                                                       \
		if (items) {                                                           \
			vector -> items = items;                                           \
			vector -> capacity = capacity;                                     \
		}                                                                      \
	}                                                                          \
	                                                                           \
	ix0 name_##_auto_resize (struct name_ * vector) {                          \
		if (vector -> size && vector -> size == vector -> capacity / 4) {      \
			name_##_resize (vector, vector -> capacity / 2);                   \
		}                                                                      \
	}                                                                          \
	                                                                           \
	/* append */                                                               \
	                                                                           \
	ix0 name_##_append (struct name_ * vector, type_ item) {                   \
		if (vector -> capacity == vector -> size) {                            \
			name_##_resize (vector, vector -> capacity * 2);                   \
		}                                                                      \
		vector -> items [vector -> size++] = item;                             \
	}                                                                          \
	                                                                           \
	ix0 name_##_append_array (struct name_ * vector, ux2 size, type_ * items) {\
		if (vector -> capacity <= vector -> size + size) {                     \
			name_##_resize (vector, next_power_of_2 (vector -> size + size));  \
		}                                                                      \
		for (ux2 i = 0; i < size; i++) {                                       \
			vector -> items [i + vector -> size] = items [i];                  \
		}                                                                      \
		vector -> size += size;                                                \
	}                                                                          \
	                                                                           \
	/* remove */                                                               \
	                                                                           \
	ix0 name_##_remove_at (struct name_ * vector, ux2 index) {                 \
		vector -> items [index] = vector -> fallback;                          \
		vector -> size--;                                                      \
		                                                                       \
		for (; index < vector -> size; index++) {                              \
			vector -> items [index] = vector -> items [index + 1];             \
			vector -> items [index + 1] = vector -> fallback;                  \
		}                                                                      \
	}

# define vector_get_at(vector_, index_)           \
	((index_ < vector_.size) ?                    \
		vector_.items [index_] : vector_.fallback \
	)

# define vector_last(vector_)                           \
	((vector_.size) ?                                   \
		vector_.items [vector_.size - 1] : vector_.fallback \
	)

# define vector_first(vector_)               \
	((vector_.size) ?                        \
		vector_.items [0] : vector_.fallback \
	)

# define vector_set_at(vector_, index_, item_) \
	if (index_ < vector_.size) {               \
		vector_.items [index_] = item_;        \
	}

# define vector_sort(vector_, compare_) \
	qsort (vector_.items, vector_.size, sizeof (* vector_.items), compare_)










