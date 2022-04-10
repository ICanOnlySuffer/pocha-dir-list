# include "lang.h"

vec dictionary;

nil lang_load_env (str path, str rescue, u16 length) FUN
	str env_lang = getenv ("LANG");
	
	IFF env_lang and str_len (env_lang) > 1 THN
		env_lang [2] = 0;
	ELS
		env_lang = rescue;
	END
	
	chr lang_path [64] = "";
	STR_CPY (lang_path, path, env_lang);
	dictionary = cnf_get (lang_path, length);
	
	IFF not dictionary.capacity THN
		PUT_ERR_ARR ("err 002: \"", lang_path, "\"\n");
		QUT (2);
	END
END

