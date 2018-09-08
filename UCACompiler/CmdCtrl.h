#pragma once
class CmdCtrl
{
public:
	CmdCtrl(int argc, char * argv[]);
	~CmdCtrl();
	std::string codefilename;
	bool lex;
	bool parserRDP;
	bool parserLL1;
	bool SA;
};

