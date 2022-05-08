# include "../inc/buffer.h"
# include "../inc/lang.h"
# include <pul/cnf.h>

vec dictionary;

nil lang_load_env (str path, str rescue, u16 length) {
	str env_lang = getenv ("LANG");
	
	if (env_lang and str_len (env_lang) > 1) {
		env_lang [2] = 0;
	} else {
		env_lang = rescue;
	}
	
	STR_CPY (BUFFER, path, env_lang);
	dictionary = cnf_get (BUFFER, length);
	
	if (not dictionary.capacity) {
		STR_CPY (BUFFER, path, rescue);
		dictionary = cnf_get (BUFFER, length);
		
		if (not dictionary.capacity) {
			PUT_ERR ("err 002: \"", BUFFER, "\"\n");
			exit (2);
		}
	}
}

