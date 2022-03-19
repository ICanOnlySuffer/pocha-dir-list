# include "lang.h"
# include "../putils/put.h"

vec * dictionary;

nil lang_load_env (str path, str rescue, u16 length) {
	chr buffer [1024] = "";
	str env_lang = getenv ("LANG");
	
	iff (env_lang) {
		env_lang [2] = 0;
		STR_CPY (buffer, path, env_lang);
		dictionary = lng_lod (buffer, length);
	}
	unl (dictionary) {
		STR_CPY (buffer, path, rescue);
		dictionary = lng_lod (buffer, length);
	}
	
	PUT (buffer);
	NEW_LNE ();
}

