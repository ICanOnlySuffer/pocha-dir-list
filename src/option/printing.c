# include "option/printing.h"

struct printing printing = {
	.colors = {"", "", "", "", ""},
	.size = false
};

nil str_frm_filesize (str buffer, u64 size) FUN
	IFF size < 1000lu THN
		sprintf (buffer, "%3lluB", size);
	ELF size < 1024lu * 10 THN
		sprintf (buffer, "%3.1fK", size / 1024.0);
	ELF size < 1024lu * 1000 THN
		sprintf (buffer, "%3lluK", size / 1024);
	ELF size < 1024lu * 1024 * 10 THN
		sprintf (buffer, "%3.1fM", size / 1024.0 / 1024);
	ELF size < 1024lu * 1000 * 1000 THN
		sprintf (buffer, "%3lluM", size / 1024 / 1024);
	ELF size < 1024lu * 1024 * 1024 * 10 THN
		sprintf (buffer, "%3.1fG", size / 1024.0 / 1024 / 1024);
	ELS
		sprintf (buffer, "%3lluG", size / 1024 / 1024 / 1024);
	END
END

nil parse_colors () FUN
	str env_colors = getenv ("LS_COLORS");
	printing.colors.reset = "\e[0m";
	
	IFF env_colors and *env_colors THN
		u08 reading = true;
		chr buffer [16];
		str color;
		
		FOR u08 i = 0, j = 2; ; env_colors++ DOS
			IFF reading THN
				IFF *env_colors == '=' THN
					reading = false;
					buffer [i] = 0;
					
					IFF STR_EQL (buffer, "di") THN
						color = printing.colors.di;
					ELF STR_EQL (buffer, "fi") THN
						color = printing.colors.fi;
					ELF STR_EQL (buffer, "ln") THN
						color = printing.colors.ln;
					ELF STR_EQL (buffer, "ex") THN
						color = printing.colors.ex;
					ELS
						color = buffer;
					END // add more here
					
					color [0] = '\e';
					color [1] = '[';
				ELS
					buffer [i++] = *env_colors;
				END
			ELS // writing
				IFF *env_colors == ':' THN
					reading = true;
					color [j] = 'm';
					i = 0;
					j = 2;
				ELF not *env_colors THN
					color [j] = 'm';
					BRK;
				ELS
					color [j++] = *env_colors;
				END
			END
		END
	END
END

nil option_printing (chr option) FUN
	SWI option DOS
	WHN 's': printing.size = true; BRK;
	WHN 'c': parse_colors (); BRK;
	default:
		help (PRINTING);
		QUT (1);
	END
END

