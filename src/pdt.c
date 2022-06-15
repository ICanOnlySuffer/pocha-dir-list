# include "../inc/option/printing.h"
# include "../inc/option.h"
# include "../inc/buffer.h"
# include "../inc/lang.h"
# include "../inc/tree.h"
# include "../inc/file.h"

s32 main (s32 argc, str args []) {
	lang_load_env (SHR_DIR "/pdt/lang/", "es");
	str path = parse_options (argc, args);
	
	str lang_n_dirs [] = {
		LANG_DIR_0,
		LANG_DIR_1,
		LANG_DIR_2,
		LANG_DIR_X
	};
	
	str lang_n_regs [] = {
		LANG_REG_0,
		LANG_REG_1,
		LANG_REG_2,
		LANG_REG_X
	};
	
	STR_CPY (BUFFER, DI_COLOR, path, NO_COLOR, "\n");
	put (BUFFER);
	tree (path);
	
	STR_FRM_FMT (
		BUFFER,
		"\n%u %s, %u %s\n",
		(u64) n_dirs,
		(u64) lang_n_dirs [n_dirs > 3 ? 3 : n_dirs],
		(u64) n_regs,
		(u64) lang_n_regs [n_regs > 3 ? 3 : n_regs]
	);
	put (BUFFER);	
}

