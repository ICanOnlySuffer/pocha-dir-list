# ifndef _PUTILS_GETCH_
# define _PUTILS_GETCH_

# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include "types.h"

// XXX SOURCE: https://stackoverflow.com/a/42220830 XXX //

chr getch () {
	struct termios old = {0};
	chr c = 0;
	
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
	
	if (read (0, &c, 1) < 0) {
		perror ("read ()");
	}
	
	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	
	if (tcsetattr (0, TCSADRAIN, &old) < 0) {
		perror ("tcsetattr ~ICANON");
	}
	
	return c;
}

# endif // _PUTILS_GETCH_

