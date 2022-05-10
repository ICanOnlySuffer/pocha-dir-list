# include "../inc/buffer.h"
# include "../inc/lang.h"
# include <stdlib.h>
# include <stdio.h>

chr LANG [ARR_LEN (LANG)][ARR_LEN (*LANG)];

nil lang_load_env (str path, str rescue) {
	str env_lang = getenv ("LANG");
	FILE * file;
	
	if (env_lang and str_len (env_lang) > 1) {
		env_lang [2] = 0;
	} else {
		env_lang = rescue;
	}
	
	STR_CPY (BUFFER, path, env_lang);
	file = fopen (BUFFER, "r");
	
	if (not file) {
		STR_CPY (BUFFER, path, rescue);
		file = fopen (BUFFER, "r");
		if (not file) {
			PUT_ERR ("err 002: \"", BUFFER, "\"\n");
			exit (2);
		}
	}
	
	u08 i = 0;
	do {
		fgets (LANG [i], ARR_LEN (*LANG), file);
		str_chp (LANG [i]);
	} while (i++ < ARR_LEN (LANG));
	
	fclose (file);
}

