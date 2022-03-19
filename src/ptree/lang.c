# include "lang.h"

vec * dictionary;

nil lang_load_env (str path, str rescue, u16 length) {
	chr buffer [1024] = "";
	str env_lang = getenv ("LANG");
	
	iff (env_lang) {
		env_lang [2] = 0;
		dictionary = lng_lod (STR_CAT (buffer, path, env_lang), length);
	}
	unl (dictionary) {
		buffer [0] = 0;
		dictionary = lng_lod (STR_CAT (buffer, path, rescue), length);
	}
}

