
enum option {
	PRINTING,
	LISTING,
	SORTING,
	OTHER
};

ix0 help (enum option option) {
	
	ix1
		* usage,
		* listing [5],
		* sorting [3],
		* printing [2];
	
	switch (lang) {
	case EN:
		usage = "usage";
		
		listing [0] = "Listing";
		listing [1] = "directories only";
		listing [2] = "files only";
		listing [3] = "both";
		listing [4] = "hidden files";
		
		sorting [0] = "Sorting";
		sorting [1] = "alphanumerically";
		sorting [2] = "directories first";
		
		printing [0] = "Printing";
		printing [1] = "color";
		
		break;
	case ES:
		usage = "uso";
		
		listing [0] = "Listado";
		listing [1] = "solo directorios";
		listing [2] = "solo arhivos";
		listing [3] = "ambos";
		listing [4] = "archivos ocultos";
		
		sorting [0] = "Odenamiento";
		sorting [1] = "alfanumérico";
		sorting [2] = "directorios primero";
		
		printing [0] = "Impresión";
		printing [1] = "color";
		
		break;
	}
	
	switch (option) {
	case OTHER:
		pputs (
			usage, ": ptree [-Ldfah] [-Sad] [-Pc]",
			"\n  -L \t", listing [0],
			"\n   -d\t> ", listing [1],
			"\n   -f\t> ", listing [2],
			"\n   -a\t> ", listing [3],
			"\n   -h\t> ", listing [4],
			
			"\n  -S \t", sorting [0],
			"\n   -a\t> ", sorting [1],
			"\n   -d\t> ", sorting [2],
			
			"\n  -P \t", printing [0],
			"\n   -c\t> ", printing [1]
		);
	}
}









