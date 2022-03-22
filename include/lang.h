
# ifndef PTREE_LANG_H
# define PTREE_LANG_H

# include <putils/lng.h>

ext vec * dictionary;
ext nil lang_load_env (str path, str rescue, u16 length);

# define LANG(key_) \
	lng_get (dictionary, key_)

# endif // PTREE_LANG_H

