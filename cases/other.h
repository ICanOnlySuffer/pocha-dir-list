
switch (*args [i]) {
case 'v':
	ix1 version [] = "v0.1.0";
	ix1 * by_me;
	ix1 * based_on_tree_by;
	ix1 people [] = "\n" \
		"  Steve Baker\n"     \
		"  Thomas Moore\n"    \
		"  Francesc Rocher\n" \
		"  Florian Sesser\n" \
		"  Kyosuke Tokoro";
	
	switch (lang) {
	case EN:
		by_me = " by ICanOnlySuffer";
		based_on_tree_by = "Based on `tree` by";
		break;
	case ES:
		by_me = " por ICanOnlySuffer";
		based_on_tree_by = "Basado en `tree` por";
	}
	
	pputs (
		"ptree ", version, by_me, "\n",
		based_on_tree_by, people
	);
	
	return;
default:
	help (option);
	return;
}









