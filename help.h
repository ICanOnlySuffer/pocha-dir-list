
enum flag {
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

ix0 help (enum flag flag) {
	switch (flag) {
	case PRINTING:
		pputs (
			"  -P    ", LANG ("printing"),
			"\n    -c    ", LANG ("printing(c)"),
			"\n    -l    ", LANG ("printing(l)"),
			"\n    -d    ", LANG ("printing(d)")
		);
		break;
	case SORTING:
		pputs (
			"  -S    ", LANG ("sorting"),
			"\n    -a    ", LANG ("sorting(a)"),
			"\n    -d    ", LANG ("sorting(d)")
		);
		break;
	case LISTING:
		pputs (
			"  -L    ", LANG ("listing"),
			"\n    -d    ", LANG ("listing(d)"),
			"\n    -r    ", LANG ("listing(r)"),
			"\n    -b    ", LANG ("listing(b)"),
			"\n    -h    ", LANG ("listing(h)")
		);
		break;
	case OTHER:
		pputs (LANG ("usage"), ": ptree [-Ldfah] [-Sad] [-Pc]");
		help (PRINTING);
		help (SORTING);
		help (LISTING);
	}
}



















