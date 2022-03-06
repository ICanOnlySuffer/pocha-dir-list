# include <stdlib.h>
# include "str.h"
# include "vec.h"

typedef struct {
	str key;
	nil * value;
} par;

par * par_new (str key, nil * value) {
	par * pair = malloc (sizeof (par));
	pair -> key = key;
	pair -> value = value;
	
	return pair;
}

str dic_get (vec * dictionary, str key) {
	for (u16 i = 0; i < dictionary -> size; i++) {
		par * pair = dictionary -> items [i];
		if (streql (pair -> key, key)) {
			return pair -> value;
		}
	}
	
	return NIL;
}

