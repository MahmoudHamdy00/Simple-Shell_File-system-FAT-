#include "Shell.h"
#include<iostream>
#include<map>
typedef void(*voidFunction) (void);
typedef long long ll;
void v() {
	std::cout << "FgggggggggggF";
}
void vv(std::map<std::string, voidFunction>& mp) {
	mp.clear();
	mp["dd"] = &v;

}
template <class T>
void func2(std::initializer_list<T> list)
{
	for (auto elem : list)
	{
		std::cout << elem << std::endl;
	}
}
int main() {
	Shell shell;
	shell.Prompt();
	//shell.help();
	//shell.help({ "dir" });

}