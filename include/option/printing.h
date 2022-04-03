
# ifndef PTREE_OPTION_PRINTING_H
# define PTREE_OPTION_PRINTING_H

# include "miscellaneous.h"
# include <stdio.h>

# define DI_COLOR printing.colors.di
# define FI_COLOR printing.colors.fi
# define LN_COLOR printing.colors.ln
# define EX_COLOR printing.colors.ex
# define NO_COLOR printing.colors.reset

struct printing {
	struct {
		chr di [8];
		chr fi [8];
		chr ln [8];
		chr ex [8];
		str reset;
	} colors;
	u08 size;
};

ext struct printing printing;
ext nil str_frm_filesize (str buffer, u64 size);
ext nil parse_colors ();
ext nil option_printing (chr option);

# endif // PTREE_OPTION_PRINTING_H

