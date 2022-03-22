# include <putils/put.h>
# include "lang.h"

vec * dictionary;

nil lang_load_env (str path, str rescue, u16 length) fun
	str env_lang = getenv ("LANG");
	
	iff env_lang and str_len (env_lang) > 2 thn
		env_lang [2] = 0;
	els
		env_lang = rescue;
	end
	
	chr lang_path [1024] = "";
	STR_CPY (lang_path, path, env_lang);
	dictionary = lng_lod (lang_path, length);
	
	iff not dictionary thn
		PUT_ERR_ARR ("couldn't load language path '", lang_path, "'\n");
		QUT (1);
	end
end

