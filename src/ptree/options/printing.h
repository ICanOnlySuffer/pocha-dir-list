
# ifndef _PTREE_OPTION_PRINTING_
# define _PTREE_OPTION_PRINTING_

# include "../../putils/extra.h"

# define di_color printing.colors.di
# define fi_color printing.colors.fi
# define ln_color printing.colors.ln
# define ex_color printing.colors.ex
# define reset_color "\e[0m"

extern struct {
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
} printing;

extern nil parse_colors ();
extern nil option_printing (str * args);

# endif // _PTREE_OPTION_PRINTING_

