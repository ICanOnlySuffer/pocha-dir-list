
# ifndef PTV_LANG_H
# define PTV_LANG_H

# include <pul/cnf.h>
# include <pul/put.h>

EXT vec dictionary;
EXT nil lang_load_env (str path, str rescue, u16 length);

# define LANG(...) \
	dic_get (&dictionary, *(u64 *)(chr [8]) {__VA_ARGS__})

# endif // PTV_LANG_H

