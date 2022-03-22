
# ifndef PTREE_OPTIONS_PRINTING_H
# define PTREE_OPTIONS_PRINTING_H

# include <putils/str.h>
# include "number.h"

# define DI_COLOR printing.colors.di
# define FI_COLOR printing.colors.fi
# define LN_COLOR printing.colors.ln
# define EX_COLOR printing.colors.ex
# define RESET_COLOR "\e[0m"

struct printing {
	struct {
		chr di [16];
		chr fi [16];
		chr ln [16];
		chr ex [16];
	} colors;
	u08 alternative;
	u32 delay;
	u08 loop;
	u08 size;
};

ext struct printing printing;
ext nil parse_colors ();
ext nil option_printing (str * args);

# endif // PTREE_OPTIONS_PRINTING_H

