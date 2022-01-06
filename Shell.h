#pragma once
#include<string>
#include<map>
#include<iostream>
#include<sstream>
#include <direct.h>
#include <vector>
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
private:
	map<string, void(Shell::*) (void)>Vfunction;
	map<string, void(Shell::*) (vector<string>)>VfunctionWithPars;
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
	void cat(vector<string>);
};

