
switch (*args [i]) {
case 'd':
	to_list = DIRECTORIES_ONLY;
	break;
case 'f':
	to_list = FILES_ONLY;
	break;
case 'b':
	to_list = BOTH;
	break;
case 'h':
	list_hidden = true;
	break;
default:
	help (LISTING);
	return;
}






