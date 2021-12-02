
switch (*args [i]) {
case 'a':
	file_compare_functions [
		n_file_compare_functions++
	] = &file_compare_alphanumerically;
	break;
case 'd':
	file_compare_functions [
		n_file_compare_functions++
	] = &file_compare_directories_first;
	break;
default:
	help (SORTING);
	return;
}



