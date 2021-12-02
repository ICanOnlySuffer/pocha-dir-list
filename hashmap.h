# include <string.h>
# include "vector.h"
# include "types.h"
# pragma once

struct hash {
	ix1 * key;
	ix1 * value;
};

define_vector (hashmap, struct hash);

ix1 * hashmap_get (struct hashmap hashmap, ix1 * key) {
	for (ux2 i = 0; i < hashmap.size; i++) {
		if (!strcmp (hashmap.items [i].key, key)) {
			return hashmap.items [i].value;
		}
	}
	return key;
}


















