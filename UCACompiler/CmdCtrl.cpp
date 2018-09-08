#include "pch.h"
#include "CmdCtrl.h"

CmdCtrl::CmdCtrl(int argc, char * argv[])
	: lex(false)
	, parserRDP(false)
	, parserLL1(false)
	, SA(false)
{
	if (argc == 3)
	{
		std::string cmdctrl(argv[1]);
		if (cmdctrl == std::string("-f"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
			parserLL1 = true;
			parserRDP = true;
			SA = true;
		}
		else if (cmdctrl == std::string("-fl"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
		}
		else if (cmdctrl == std::string("-flr"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
			parserRDP = true;
		}
		else if (cmdctrl == std::string("-fll"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
			parserLL1 = true;
		}
		else if (cmdctrl == std::string("-flrs"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
			parserRDP = true;
			SA = true;
		}
		else if (cmdctrl == std::string("-flls"))
		{
			codefilename = std::string(argv[2]);
			lex = true;
			parserLL1 = true;
			SA = true;
		}
	}
}

CmdCtrl::~CmdCtrl()
{
}
