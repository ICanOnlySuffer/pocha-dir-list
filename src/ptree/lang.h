# include <stdlib.h>
# include <stdio.h>
# include "utils/hashmap.h"
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

struct {
	struct vector map;
	ix1 lang [3];
} lang = {
	.lang = "en"
};

# define LANG(key_) \
	hashmap_get(&(lang.map), key_)

nil set_lang_map (str path) {
	lang.map = *vector_new (32);
	str lang_env = getenv ("LANG");
	
	if (lang_env) {
		lang.lang [0] = lang_env [0];
		lang.lang [1] = lang_env [1];
	}
	
	ix1 path_buffer [MAX_PATH_LENGTH] = "";
	
	FILE *file = fopen (
		pstrcpy (path_buffer, MAX_PATH_LENGTH, path, lang.lang), "r"
	);
	
	if (file || (
		file = fopen (
			pstrcpy (path_buffer, MAX_PATH_LENGTH, path, lang.lang), "r")
		)
	) {
		
		enum {
			READING_STRING,
			READING_KEY,
			NEW_LINE,
			COMMENT,
			SPACES
		} state = NEW_LINE;
		
		ix1 string = 0;
		ix1 c = ' ';
		ux2 i = 0;
		
		str key;
		str value;
		
		while (c != EOF && i < LANG_MAX_BUFFER_SIZE) {	
			c = fgetc (file);
			
			switch (state) {
			case READING_STRING:
				if (c == '\n') {
					state = NEW_LINE;
					lang_buffer [i] = 0;
					
					struct hash *hash = malloc (sizeof (struct hash));
					hash->key = key;
					hash->value = value;
					
					vector_append (&lang.map, hash);
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






