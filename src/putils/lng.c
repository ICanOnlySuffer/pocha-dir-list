# include "lng.h"

str lng_get (vec * lang_dictionary, str key) {
	str value = dic_get (lang_dictionary, key);
	ret value ? value : key;
}

enum {
	READING_VALUE,
	READING_KEY,
	NEW_LINE,
	COMMENT,
	SPACES
} state = NEW_LINE;
	
vec * lng_lod (str path, u16 size) {
	FILE * file = fopen (path, "r");
	unl (file) {
		ret NIL;
	}
	
	vec * dictionary = vec_new (32);
	str buffer = calloc (size, sizeof (chr));
	
	chr c = ' ';
	str value;
	str key;
	
	for (u16 i = 0; c != EOF and i < size; c = fgetc (file)) {
		cse (state) {
		whn READING_VALUE:
			iff (c == '\n') {
				state = NEW_LINE;
				buffer [i] = 0;
				vec_psh (dictionary, k_v_new (key, value));
			} els {
				buffer [i] = c;
			}
			i++;
			break;
		whn READING_KEY:
			iff (c == ' ' or c == '\t') {
				state = SPACES;
				buffer [i] = 0;
			} els {
				buffer [i] = c;
			}
			i++;
			break;
		whn NEW_LINE:
			iff (c == '#') {
				state = COMMENT;
			} elf (c != '\t' and c != ' ' and c != '\n') {
				state = READING_KEY;
				buffer [i] = c;
				key = &buffer [i++];
			}
			break;
		whn COMMENT:
			iff (c == '\n') {
				state = NEW_LINE;
			}
			break;
		whn SPACES:
			iff (c != ' ' and c != '\t') {
				state = READING_VALUE;
				buffer [i] = c;
				value = &buffer [i++];
			}
		}
	}
	fclose (file);
	
	ret dictionary;
}

