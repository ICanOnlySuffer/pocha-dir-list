# include "option/printing.h"

struct printing printing = {
	.colors = {"", "", "", "", ""},
	.size = false
};

nil str_frm_filesize (str buffer, u64 size) FUN
	chr character;
	IFF size < 9999lu THN
		character = 'B';
	ELF size < 9999lu * 1024 THN
		character = 'K';
		size /= 1024;
	ELF size < 9999lu * 1024 * 1024 THN
		character = 'M';
		size /= 1024 * 1024;
	ELS
		character = 'G';
		size /= 1024 * 1024 * 1024;
	END
	u08 len = size < 10 ? 1 : size < 100 ? 2 : size < 1000 ? 3 : 4;
	str_frm_u64 (buffer + 4 - len, size);
	buffer [4] = character;
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

