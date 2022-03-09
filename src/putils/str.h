
# ifndef _PUTILS_STR_
# define _PUTILS_STR_

# include <string.h>
# include "inc.h"

extern u64 str_len (str string);
extern nil str_rvs (str string);
extern nil u64_tos (u64 number, str buffer);

# define streql(string_1_, string_2_) \
	(not strcmp (string_1_, string_2_))

# endif // _PUTILS_STR_

