#include "Shell.h"
#include<iostream>
#include<map>
typedef void(*voidFunction) (void);
typedef long long ll;
void v() {
	std::cout << "FgggggggggggF";
}
void vv(std::map<std::string, voidFunction>&mp) {
	mp.clear();
	mp["dd"] = &v;

}
int main() {
	//Shell shell;
	//shell.Prompt();
	std::map<std::string, voidFunction>mp;
	vv(mp);
	mp["dd"]();
}