# include "lng.h"

str lng_get (vec * lang_dictionary, str key) {
	str value = dic_get (lang_dictionary, key);
	return value ? value : key;
}

vec * lng_load (str path, str rescue, u16 size) {
	vec * lang_dictionary = vec_new (32);
	str lang_buffer = calloc (size, sizeof (chr));
	str lang_env = getenv ("LANG");
	chr lang_str [] = {lang_env [0], lang_env [1], 0};
	
	FILE * file;
	chr path_buffer [PATH_SIZE];
	
	STR_CPY (path_buffer, PATH_SIZE, path, lang_str);
	file = fopen (path_buffer, "r");
	
	unless (file) {
		STR_CPY (path_buffer, PATH_SIZE, path, rescue);
		file = fopen (path_buffer, "r");
	}
	
	if (file) {
		enum {
			READING_VALUE,
			READING_KEY,
			NEW_LINE,
			COMMENT,
			SPACES
		} state = NEW_LINE;
		
		chr string = 0;
		chr c = ' ';
		u16 i = 0;
		str value;
		str key;
		
		while ((c = fgetc (file)) != EOF and i < size) {
			switch (state) {
			case READING_VALUE:
				if (c == '\n') {
					state = NEW_LINE;
					lang_buffer [i] = 0;
					vec_append (lang_dictionary, par_new (key, value));
				} else {
					lang_buffer [i] = c;
				}
				i++;
				break;
			case READING_KEY:
				if (c == ' ' or c == '\t') {
					state = SPACES;
					lang_buffer [i] = 0;
				} else {
					lang_buffer [i] = c;
				}
				i++;
				break;
			case NEW_LINE:
				if (c == '#') {
					state = COMMENT;
				} elif (c != '\t' and c != ' ' and c != '\n') {
					state = READING_KEY;
					lang_buffer [i] = c;
					key = &lang_buffer [i++];
				}
				break;
			case COMMENT:
				if (c == '\n') {
					state = NEW_LINE;
				}
				break;
			case SPACES:
				if (c != ' ' and c != '\t') {
					state = READING_VALUE;
					lang_buffer [i] = c;
					value = &lang_buffer [i++];
				}
			}
		}
		fclose (file);
	}
	
	return lang_dictionary;
}

