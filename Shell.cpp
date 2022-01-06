#include "Shell.h"
#include <iomanip>
void Shell::Prompt() {
	while (true) {
		cout << currentDirictory << ">";
		string curLine;
		getline(cin, curLine);

		stringstream data(curLine);
		string cmd;
		data >> cmd;
		if (cmd.empty())continue;
		vector<string>parameters;
		string tmp;
		while (data >> tmp)parameters.push_back(tmp);
		if (commands.find(cmd) == commands.end()) {
			cout << '\'' << cmd << "\' is not recognized as an internal or external command,operable program or batch file.\n";
		}
		else {
			if (Vfunction.find(cmd) != Vfunction.end()) {
				(this->*Vfunction[cmd])();
			}
			else if (VfunctionWithPars.find(cmd) != VfunctionWithPars.end()) {
				(this->*VfunctionWithPars[cmd])(parameters);
			}
			else
				cout << "Not Implemented Yet";
			cout << endl;
		}

	}
}
void Shell::getCommands(map<string, string>& commands) {
	commands.clear();
	commands["cd"] = "Change the current default directory to.If the argument is not present, report the current directory.If the directory does not exist an appropriate error should be reported.";
	commands["clr"] = "Clear the screen.";
	commands["cat"] = "Concatenate FILE(s) to standard output.";
	commands["dir"] = "List the contents of directory .";
	commands["help"] = "Display the user manual using the more filter.";
	commands["help"] += ",Provides Help information for commands.";
	commands["quit"] = "Quit the shell.";
	commands["exit"] = "Quit the shell.";
	commands["copy"] = "Copies one or more files to another location";
	commands["del"] = "Deletes one or more files.";
	commands["md"] = "Creates a directory.";
	commands["mkdir"] = "Creates a directory.";
	commands["rd"] = "Removes a directory.";
	commands["rmdir"] = "Removes a directory.";
	commands["rename"] = "Renames a file.";
	commands["type"] = "Displays the contents of a text file.";
	commands["import"] = "import text file(s) from your computer";
	commands["export"] = "export text file(s) to your computer";
}

void Shell::buildFunctionMap(map<string, void(Shell::*) (void)>& mp) {
	mp.clear();
	mp["exit"] = &Shell::myExit;
	mp["quit"] = &Shell::myExit;
	mp["clr"] = &Shell::clear;
	mp["dir"] = &Shell::dir;
}
void Shell::buildFunctionMap(map<string, void(Shell::*) (vector<string>)>& mp) {
	mp.clear();
	mp["help"] = &Shell::help;
	mp["md"] = &Shell::mkdir;
	mp["mkdir"] = &Shell::mkdir;
	mp["rd"] = &Shell::rmdir;
	mp["rmdir"] = &Shell::rmdir;
	mp["cat"] = &Shell::cat;
}
void Shell::myExit() {
	exit(0);
}

void Shell::help(vector<string>parameters) {
	if (parameters.empty()) {
		for (auto it : commands) {
			cout << "	" << it.first << setw(10 - it.first.size()) << " -> " << it.second << endl;
		}

	}
	else if (commands.find(parameters[0]) != commands.end())
		cout << commands[parameters[0]] << endl;
	else cout << "This command is not supported by the help utility.\n";
}
void Shell::clear() {
	system("clear");
}
void Shell::dir() {
	system("dir");
}
void Shell::mkdir(vector<string>parameters) {
	if (parameters.size() != 1) {
		cout << "The syntax of the command is incorrect.\n";
		return;
	}
	string dirictoryName = parameters[0];
	char* char_arr;
	char_arr = &dirictoryName[0];
	if (!~_mkdir(char_arr))//when equal -1 -> failed   (!~-1 ==0)
		cout << "Faild to create dirictory\n";

}
void Shell::rmdir(vector<string>parameters) {
	if (parameters.size() == 0) {
		cout << "The syntax of the command is incorrect.\n";
		return;
	}
	for (string cur : parameters) {
		char* char_arr;
		char_arr = &cur[0];
		if (!~_rmdir(char_arr))//when equal (-1) -> failed   (!~-1 ==0)
			cout << cur << " :The system cannot find the file specified.\n";
	}
}
void Shell::cat(vector<string>parameters) {
	if (parameters.size() == 0) {
		cout << "The syntax of the command is incorrect.\n";
		return;
	}
	for (string cur : parameters) {
		cur = "cat " + cur;
		const char* char_arr = &cur[0];
		system(char_arr);
	}
}