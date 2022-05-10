
# ifndef PTV_OPTION_PRINTING_H
# define PTV_OPTION_PRINTING_H

# include "miscellaneous.h"

# define DI_COLOR printing.colors.di
# define FI_COLOR printing.colors.fi
# define LN_COLOR printing.colors.ln
# define EX_COLOR printing.colors.ex
# define NO_COLOR printing.colors.reset

ext struct printing {
	struct {
		chr di [8];
		chr fi [8];
		chr ln [8];
		chr ex [8];
		str reset;
	} colors;
	u08 size;
} printing;

ext nil str_frm_size (str destine, u64 size);
ext nil parse_colors ();
ext nil option_printing (chr option);

# endif // PTV_OPTION_PRINTING_H

