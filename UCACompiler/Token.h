#pragma once
#include "pch.h"
#include "Buffer.h"
class Token
{
public:
	enum LexType
	{
		PROGRAM,
		TYPE,
		INTEGER,
		ARRAY,
		OF,
		VAR,
		PROCEDURE,
		BEGIN,
		WRITE,
		END,
		WHILE,
		DO,
		ENDWH,
		RECORD,
		READ,
		IF,
		THEN,
		ELSE,
		FI,
		CHAR,
		RETURN,
		ID,
		INTC,
		ASSIGN,//:=
		ARRAYT,
		CHART,
		EOFT,
		
		SEMI,//;
		EQ,//=
		LS,//(
		RS,//)
		LM,//[
		RM,//]
		PLUS,//+
		SUB,//-
		MUL,//*
		DIV,///
		DOT,//.
		COMMA,//,
		LT,//<
		TAB,//\t
		SPACE,
		ENTER
	};
	Token();
	~Token();
	Token(int lineNumber, LexType lexType, string sem);
	void SetToken(FileOpModule & fileOpModule, State::TerminalState terminal, Buffer & buf);
	void Out();
//private:
	int m_lineNumber;
	LexType m_lexType;
	string m_sem;
	std::string GetLexType();
	static std::string GetLexType(const LexType lexType);
private:
	LexType ReservedLookup(std::string str);
	LexType BorderLookup(std::string str);
	
};

