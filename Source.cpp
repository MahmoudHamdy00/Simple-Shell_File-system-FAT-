#include "Shell.h"
string developer = "Mahmoud Hamdy";
string version = "[Version 1.0]";
int main() {
	cout << developer << " " << version << "\n\n";
	Shell shell;
	shell.Prompt();
}