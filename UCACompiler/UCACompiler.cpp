#include "pch.h"
#include "Lexer.h"

int main(int argc, char ** argv)
{
	CmdCtrl cmdCtrl(argc, argv);
	//std::wstring fileName(L"test.txt");
	FileOpModule fileOpModule(cmdCtrl.codefilename);
	//FileOpModule fileOpModule(fileName);
	Lexer lexer(fileOpModule);
	if (cmdCtrl.lex)
	{
		lexer.Out();
		std::cout << "----------Lexer Analyze Done!----------" << std::endl;
	}
	Parser_RDP parserRDP(lexer.GetTokenList());
	if (cmdCtrl.parserRDP)
	{
		parserRDP.Out();
		std::cout << "----------Parser RDP Done!----------" << std::endl;
	}
	Parser_LL1 parserLL1(lexer.GetTokenList());
	if (cmdCtrl.parserLL1)
	{
		parserLL1.Out();
		std::cout << "----------Parser LL1 Done!----------" << std::endl;
	}
	Signal_Table signaltable;
	if (cmdCtrl.SA)
	{
		signaltable.Createtable(parserRDP.ReturnRoot());
		std::cout << "----------Signal Table Done!----------" << std::endl;
	}

}
