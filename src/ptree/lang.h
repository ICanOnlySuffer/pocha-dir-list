
# ifndef _PTREE_LANG_
# define _PTREE_LANG_

# include "../putils/lng.h"

extern vec * lang_map;

# define LANG(key_) \
	lng_get (lang_map, key_)

# endif // _PTREE_LANG_

