
# ifndef _PTREE_LANG_
# define _PTREE_LANG_

# include "../putils/lng.h"

ext vec * dictionary;
ext nil lang_load_env (str path, str rescue, u16 length);

# define LANG(key_) \
	lng_get (dictionary, key_)

# endif // _PTREE_LANG_

