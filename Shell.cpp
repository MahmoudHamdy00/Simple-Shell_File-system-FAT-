#include "Shell.h"

void Shell::Prompt()
{
	while (true) {
		cout << currentDirictory << ">";
		string curLine;
		getline(cin, curLine);

		stringstream data(curLine);
		string cmd;
		data >> cmd;

		if (commands.find(cmd) == commands.end()) {
			cout << '\'' << cmd << "\' is not recognized as an internal or external command,operable program or batch file.\n";
		}
		else {
			if (Vfunction.find(cmd) == Vfunction.end()) {
				cout << "Not Implemented Yet\n";
				continue;
			}
			*(Vfunction[cmd])();
		}

	}
}
void Shell::getCommands(map<string, string>& commands) {
	commands.clear();
	commands["cd"] = " - Change the current default directory to.If the argument is not present, report the current directory.If the directory does not exist an appropriate error should be reported.";
	commands["clr"] = " - Clear the screen.";
	commands["dir"] = " - List the contents of directory .";
	commands["help"] = " - Display the user manual using the more filter.";
	commands["quit"] = " - Quit the shell.";
	commands["exit"] = " - Quit the shell.";
	commands["copy"] = " - Copies one or more files to another location";
	commands["del"] = " - Deletes one or more files.";
	//commands["help"] = " - Provides Help information for commands.";
	commands["md"] = " - Creates a directory.";
	commands["rd"] = " - Removes a directory.";
	commands["rename"] = " - Renames a file.";
	commands["type"] = " - Displays the contents of a text file.";
	commands["import"] = " – import text file(s) from your computer";
	commands["export"] = "export text file(s) to your computer";
}

void Shell::buildFunctionMap(map<string, void(Shell::*) (void)>& mp) {
	mp.clear();
	mp["exit"] = &Shell::myExit;
	//mp["help"] = &Shell::help;
}

void Shell::myExit()
{
	exit(0);
}
void Shell::help()
{
	for (auto it : Shell::commands) {
		cout << it.first << '\t' << it.second << endl;
	}
}