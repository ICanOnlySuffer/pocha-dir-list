# include "lang.h"

vec dictionary;

nil lang_load_env (str path, str rescue, u16 length) {
	str env_lang = getenv ("LANG");
	
	if (env_lang and str_len (env_lang) > 1) {
		env_lang [2] = 0;
	} else {
		env_lang = rescue;
	}
	
	chr lang_path [64] = "";
	STR_CPY (lang_path, path, env_lang);
	dictionary = cnf_get (lang_path, length);
	
	if (not dictionary.capacity) {
		STR_CPY (lang_path, path, rescue);
		dictionary = cnf_get (lang_path, length);
	}
	
	if (not dictionary.capacity) {
		PUT_ERR_ARR ("err 002: \"", lang_path, "\"\n");
		exit (2);
	}
}

