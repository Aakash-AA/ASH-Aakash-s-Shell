/*
	The program execution starts here, main has only function calls and the exit condition.
*/

#ifndef SHELL_H
#include"Shell.h"
#endif
#ifndef VARIABLE_H
#include"Variables.h"
#endif
#ifndef FUNC_H
#include"Functions.h"
#endif

int main()
{
	install_signal(SIGCHLD, child_handler);
	initialize_disp();
	get_home();
	clear_disp();
	
	uflag = 0;
	while(1)
	{
		ash_main();
		if(uflag)
		{
			// Exits the program, but doesn't handle children
			exit(0);
		}
	}
}