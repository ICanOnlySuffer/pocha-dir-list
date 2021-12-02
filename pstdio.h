# include <stdio.h>
# include "types.h"
# pragma once

ix0 pprint_ (ux2 size, ix1 * strings []) {
	
	for (ux2 i = 0; i < size; i++) {
		while (*strings [i]) {
			putchar (*strings [i]++);
		}
	}
	
}

# define pprint(...)                                         \
	pprint_ (                                                \
		sizeof ((char *[]) {__VA_ARGS__}) / sizeof (char *), \
		(char *[]) {__VA_ARGS__}                             \
	)

# define pputs(...) \
	pprint (__VA_ARGS__, "\n")









