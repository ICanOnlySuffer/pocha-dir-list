# include "options/printing.h"

struct printing printing = {
	.alternative = false,
	.colors = {"", "", "", ""},
	.delay = 10,
	.loop = false,
	.size = false
};

nil parse_colors () fun
	str env_colors = getenv ("LS_COLORS");
	
	iff env_colors and *env_colors thn
		u08 reading = true;
		chr buffer [16];
		str color;
		
		for u08 i = 0, j = 2; ; env_colors++ dos
			iff reading thn
				iff *env_colors == '=' thn
					reading = false;
					buffer [i] = 0;
					
					iff STR_EQL (buffer, "di") thn
						color = printing.colors.di;
					elf STR_EQL (buffer, "fi") thn
						color = printing.colors.fi;
					elf STR_EQL (buffer, "ln") thn
						color = printing.colors.ln;
					elf STR_EQL (buffer, "ex") thn
						color = printing.colors.ex;
					els
						color = buffer;
					end
					
					color [0] = '\e';
					color [1] = '[';
				els
					buffer [i++] = *env_colors;
				end
			els // writing
				iff *env_colors == ':' thn
					reading = true;
					color [j] = 'm';
					i = 0;
					j = 2;
				elf not *env_colors thn
					color [j] = 'm';
					break;
				els
					color [j++] = *env_colors;
				end
			end
		end
	end
end

nil option_printing (str * args) fun
	swi **args dos
	whn 'd': printing.delay = parse_number (args); break;
	whn 'a': printing.alternative = true; break;
	whn 'l': printing.loop = true; break;
	whn 's': printing.size = true; break;
	whn 'c': parse_colors (); break;
	def:
		help (PRINTING);
		QUT (1);
	end
end

