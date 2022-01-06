#pragma once
#include<string>
#include<map>
#include<iostream>
#include<sstream>
#include <cstdarg>
#include <direct.h>
///typedef void(Shell::* voidFunction) (void);

using namespace std;

class Shell
{
public:
	Shell() {
		char buff[FILENAME_MAX];
		currentDirictory = string(_getcwd(buff, FILENAME_MAX));
		getCommands(commands);
		buildFunctionMap(Vfunction);
	}
	void Prompt();
	map<string, void(Shell::*) (void)>Vfunction;

	template <class T>
	void help(std::initializer_list<T> list);
private:
	string currentDirictory;
	map<string, string>commands;
	void getCommands(map<string, string>& commands);
	void buildFunctionMap(map<string, void(Shell::*) (void)>& mp);
	void myExit();
	void help();
	//void help(...);

};

