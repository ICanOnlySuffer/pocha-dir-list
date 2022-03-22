# include "options/sorting.h"

s32 compare_name (con ptr file_1, con ptr file_2) fun
	ret str_cmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
end

s32 compare_is_dir (con ptr file_1, con ptr file_2) fun
	ret (
		S_ISDIR ((*(struct file **) file_2) -> mode) -
		S_ISDIR ((*(struct file **) file_1) -> mode)
	);
end

vec * compare_functions = NIL;

nil option_sorting (str * options) fun
	iff not compare_functions thn
		compare_functions = vec_new (4);
	end
	
	swi **options dos
	whn 'n':
		vec_psh (
			compare_functions,
			compare_name
		);
		break;
	whn 'd':
		vec_psh (
			compare_functions,
			compare_is_dir
		);
		break;
	def:
		help (SORTING);
		QUT (1);
	end
end

