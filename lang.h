# include <stdlib.h>

# include "hashmap.h"
# include "pstring.h"
# pragma once

# ifndef LANG_MAX_BUFFER_SIZE
# define LANG_MAX_BUFFER_SIZE 4096
# endif

# ifndef LANG_MAP_MAX_BUFFER_SIZE
# define LANG_MAP_MAX_BUFFER_SIZE 32
# endif

# ifndef MAX_PATH_LENGTH
# define MAX_PATH_LENGTH 1024
# endif

ix1 lang_buffer [LANG_MAX_BUFFER_SIZE];

struct hashmap lang_map;

# define LANG(key_) \
	hashmap_get(lang_map, key_)

ix0 lang_compile (ix1 * path) {
	ix1 * lang_env = getenv ("LANG");
	ix1 lang [] = "en";
	
	if (lang_env) {
		lang [0] = lang_env [0];
		lang [1] = lang_env [1];
	}
	
	ix1 path_buffer [MAX_PATH_LENGTH] = "";
	
	FILE * file = fopen (
		pstrcat (path_buffer, MAX_PATH_LENGTH, path, lang), "r"
	);
	
	path_buffer [0] = 0;
	
	if (file || (
		file = fopen (
			pstrcat (path_buffer, MAX_PATH_LENGTH, path, lang), "r")
		)
	) {
		ux2 i = 0;
		ix1 string = 0;
		ix1 c = ' ';
		
		enum {
			READING_STRING,
			READING_KEY,
			NEW_LINE,
			COMMENT,
			SPACES
		} state = NEW_LINE;
		
		ix1 * key;
		ix1 * value;
		
		while (c != EOF && i < LANG_MAX_BUFFER_SIZE) {	
			c = fgetc (file);
			
			switch (state) {
			case READING_STRING:
				if (c == '\n') {
					state = NEW_LINE;
					lang_buffer [i] = 0;
					struct hash lang_hash = {key, value};
					hashmap_append (&lang_map, lang_hash);
				} else {
					lang_buffer [i] = c;
				}
				i++;
				break;
			case READING_KEY:
				if (c == ' ' || c == '\t') {
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
				} else if (c != '\t' && c != ' ' && c != '\n') {
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
				if (c != ' ' && c != '\t') {
					state = READING_STRING;
					lang_buffer [i] = c;
					value = &lang_buffer [i++];
				}
				break;
			}
		}
		
		fclose (file);
	}
}






