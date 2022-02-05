# ifndef _PUTILS_HASHMAP_
# define _PUTILS_HASHMAP_

# include "string.h"
# include "vector.h"

struct hash {
	str key;
	nil * value;
};

struct hash * hash_new (str key, nil * value) {
	struct hash * hash = malloc (sizeof (struct hash));
	hash -> key = key;
	hash -> value = value;
	
	return hash;
}

str hashmap_get (vec * hashmap, str key) {
	for (u16 i = 0; i < hashmap -> size; i++) {
		struct hash * hash = hashmap -> items [i];
		if (streql (hash -> key, key)) {
			return hash -> value;
		}
	}
	
	return NIL;
}

# endif // _PUTILS_HASHMAP_

