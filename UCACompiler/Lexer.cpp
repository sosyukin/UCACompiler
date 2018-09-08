#include "pch.h"
#include "Lexer.h"


Lexer::Lexer(FileOpModule & fileOpModule)
	: lineNumber(0)
{
	std::list<State> stateList;
	std::list<Map> mapList;
	InitAutomaton(stateList, mapList);
	Automaton automaton(stateList, mapList);
	automaton.Start();
	while (!fileOpModule.eof())
	{
		char code = fileOpModule.Get();
		automaton.Get(identifier.Check(code));
		buffer.Add(code);
		State::TerminalState EndState = automaton.End();
		if (EndState == State::Comment)
		{
			while (fileOpModule.Get() != '}');
			automaton.Start();
		}
		else if (EndState == State::Eof)
		{
			token_temp.SetToken(fileOpModule, EndState, buffer);
			buffer.Clear();
			//tokenList.Add(Token(token_temp.m_lineNumber-1,Token::DOT,"."));
			tokenList.Add(token_temp);
			automaton.Start();
			break;
		}
		else if (EndState != State::Null)
		{
			token_temp.SetToken(fileOpModule, EndState, buffer);
			if (token_temp.m_lexType != Token::SPACE && token_temp.m_lexType != Token::ENTER && token_temp.m_lexType != Token::TAB)
			{
				tokenList.Add(token_temp);
			}
			automaton.Start();
		}
		else
		{
			continue;
		}
	}
	
}


Lexer::~Lexer()
{
}


TokenList Lexer::GetTokenList()
{
	return tokenList;
}


void Lexer::Out()
{
	tokenList.Out();
}
