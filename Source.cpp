#include<iostream>
#include<sstream>

#include<map>
#include<string>

using namespace std;
void getCommands(map<string, string>& commands) {
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
enum string_code {
	cd, clr, dir, help, quit, copy, del, md, Exit
};

string_code hashit(string const& inString) {
	if (inString == "exit") return string_code::Exit;
}
int main() {
	map<string, string>commands;
	getCommands(commands);


	string currentDirictory = "E:\\GitHub\\Simple Shell_File system (FAT)";

	while (1) {
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
			//print description
			cout << commands[cmd] << endl;

			//execute
			switch (hashit(cmd))
			{
			case string_code::Exit:
				exit(0);
			default:
				break;
			}
		}

	}
}