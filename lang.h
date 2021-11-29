# include "types.h"
# pragma once

enum {
	EN, // Canadian
	ES  // Peruvian
} lang = EN;

# define set_lang()                   \
	ix1 * env_lang = getenv ("LANG"); \
	if (env_lang) {                   \
		switch (env_lang [0]) {       \
		case 'e':                     \
			switch (env_lang [1]) {   \
			case 's':                 \
				lang = ES;            \
			}                         \
		}                             \
	}





