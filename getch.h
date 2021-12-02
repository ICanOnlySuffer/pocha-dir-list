# include <termios.h>
# include <unistd.h>
# include "types.h"
# pragma once

ix1 getch () {
	struct termios old = {0};
	ix1 buffer = 0;
	
	fflush (stdout);
	
	if (tcgetattr (0, &old) < 0) {
		perror ("tcsetattr ()");
	}
	
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc [VMIN] = 1;
	old.c_cc [VTIME] = 0;
	
	if (tcsetattr (0, TCSANOW, &old) < 0) {
		perror ("tcsetattr ICANON");
	}
	
	if (read (0, &buffer, 1) < 0) {
		perror ("read()");
	}
	
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	
	if (tcsetattr(0, TCSADRAIN, &old) < 0) {
		perror ("tcsetattr ~ICANON");
	}
	
	return buffer;
}









