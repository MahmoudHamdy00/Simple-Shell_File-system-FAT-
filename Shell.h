#pragma once
#include<string>
#include<map>
#include<iostream>
#include<sstream>
#include <cstdarg>
#include <direct.h>
#include <vector>
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
		buildFunctionMap(VfunctionWithPars);
	}
	void Prompt();
	map<string, void(Shell::*) (void)>Vfunction;
	map<string, void(Shell::*) (vector<string>)>VfunctionWithPars;

	template <class T>
	void help(std::initializer_list<T> list);
private:
	string currentDirictory;
	map<string, string>commands;
	void getCommands(map<string, string>& commands);
	void buildFunctionMap(map<string, void(Shell::*) (void)>& mp);
	void buildFunctionMap(map<string, void(Shell::*) (vector<string>)>& mp);
	void myExit();
	void help(vector<string>);
	void clear();
	void dir();
	void mkdir(vector<string>);
	void rmdir(vector<string>);
	//void help(...);

};

