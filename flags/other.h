
switch (*args [i]) {
case 'v':
	ix1 people [] = "\n  "  \
		"Steve Baker, "     \
		"Thomas Moore, "    \
		"Francesc Rocher, " \
		"Florian Sesser & " \
		"Kyosuke Tokoro";
	
	pputs (
		"ptree v0.2.0 - ICanOnlySuffer\n",
		LANG ("credits"), people, "\n",
		LANG ("copyright")
	);
	
	return;
default:
	help (OTHER);
	return;
}









