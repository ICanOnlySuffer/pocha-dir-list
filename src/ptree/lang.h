# ifndef _PTREE_LANG_
# define _PTREE_LANG_

# include "../putils/hashmap.h"
# include <stdlib.h>
# include <stdio.h>

# ifndef LANG_MAX_BUFFER_SIZE
# define LANG_MAX_BUFFER_SIZE 4096
# endif

# ifndef LANG_MAP_MAX_BUFFER_SIZE
# define LANG_MAP_MAX_BUFFER_SIZE 32
# endif

# ifndef MAX_PATH_SIZE
# define MAX_PATH_SIZE 1024
# endif

chr lang_buffer [LANG_MAX_BUFFER_SIZE];
vec * lang_map = NULL;

# define LANG(key_) \
	hashmap_get(lang_map, key_)

nil set_lang_map (str path) {
	lang_map = vector_new (32);
	str lang_env = getenv ("LANG");
	chr lang [3] = "en";
	
	if (lang_env) {
		lang [0] = lang_env [0];
		lang [1] = lang_env [1];
	} else {
		return;
	}
	
	chr path_buffer [MAX_PATH_SIZE] = "";
	pstrcpy (path_buffer, MAX_PATH_SIZE, path, lang);
	
	FILE * file = fopen (path_buffer, "r");
	
	if (file || (
		file = fopen (
			pstrcpy (path_buffer, MAX_PATH_SIZE, path, lang), "r")
		)
	) {
		
		enum {
			READING_STRING,
			READING_KEY,
			NEW_LINE,
			COMMENT,
			SPACES
		} state = NEW_LINE;
		
		chr string = 0;
		chr c = ' ';
		u16 i = 0;
		
		str key;
		str value;
		
		while (c != EOF && i < LANG_MAX_BUFFER_SIZE) {	
			c = fgetc (file);
			
			switch (state) {
			case READING_STRING:
				if (c == '\n') {
					state = NEW_LINE;
					lang_buffer [i] = 0;
					vector_append (lang_map, hash_new (key, value));
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
				} else if (c != '\t' and c != ' ' and c != '\n') {
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

# endif // _PTREE_LANG_




