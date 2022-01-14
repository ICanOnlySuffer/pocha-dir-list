# include "pstring.h"
# include "vector.h"
# include "types.h"
# pragma once

struct hash {
	str key;
	str value;
};

str hashmap_get (struct vector *hashmap, str key) {
	for (ux2 i = 0; i < hashmap->size; i++) {
		if (streql (((struct hash *) (hashmap->items [i]))->key, key)) {
			key = ((struct hash *) (hashmap->items [i]))->value;
			break;
		}
	}
	
	return key;
}


















