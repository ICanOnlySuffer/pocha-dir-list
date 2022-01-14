# include <stdio.h>
# include "types.h"
# pragma once

nil pprint_ (ux2 size, str strings []) {
	for (ux2 i = 0; i < size; i++) {
		while (*strings [i]) {
			putchar (*strings [i]++);
		}
	}
}

# define pprint(...)                                    \
	pprint_ (                                           \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# define pputs(...) \
	pprint (__VA_ARGS__, "\n")









