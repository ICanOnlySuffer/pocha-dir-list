# ifndef PTREE_LANG_
# define PTREE_LANG_

# include "../putils/lang.h"

vec * lang_map;

# define LANG(key_) \
	lang_get (lang_map, key_)

# endif // PTREE_LANG_

