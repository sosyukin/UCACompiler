#include "pch.h"
#include "Token.h"


Token::Token()
{
}


Token::~Token()
{
}


Token::Token(int lineNumber, LexType lexType, string sem)
	: m_lineNumber(lineNumber)
	, m_lexType(lexType)
	, m_sem(sem)
{
}


void Token::SetToken(FileOpModule & fileOpModule, State::TerminalState terminal, Buffer & buf)
{
	switch (terminal)
	{
	case State::ID:
		buf.Back();
		fileOpModule.Back();
		m_lexType = ReservedLookup(buf.Get());
		m_sem = buf.Get();
		break;
	case State::Integer:
		buf.Back();
		fileOpModule.Back();
		m_lexType = INTC;
		m_sem = buf.Get();
		break;
	case State::Border:
		m_lexType = BorderLookup(buf.Get());
		m_sem = buf.Get();
		break;
	case State::Assign:
		m_lexType = ASSIGN;
		m_sem = buf.Get();
		break;
	case State::Array:
		m_lexType = ARRAYT;
		m_sem = buf.Get();
		break;
	case State::Char:
		m_lexType = CHART;
		m_sem = buf.Get();
		break;
	case State::Eof:
		m_lexType = EOFT;
		m_sem = "EOF";
		break;
	default:
		break;
	}
	m_lineNumber = fileOpModule.GetLineNum();
	buf.Clear();
}

void Token::Out()
{
	using namespace std;
	cout << setw(4) << m_lineNumber << setw(10) << GetLexType() << setw(10) << m_sem << endl;
}


Token::LexType Token::ReservedLookup(std::string str)
{
	if (str == "program")
	{
		return PROGRAM;
	}
	else if (str == "type")
	{
		return TYPE;
	}
	else if (str == "integer")
	{
		return INTEGER;
	}
	else if (str == "array")
	{
		return ARRAY;
	}
	else if (str == "of")
	{
		return OF;
	}
	else if (str == "var")
	{
		return VAR;
	}
	else if (str == "procedure")
	{
		return PROCEDURE;
	}
	else if (str == "begin")
	{
		return BEGIN;
	}
	else if (str == "write")
	{
		return WRITE;
	}
	else if (str == "end")
	{
		return END;
	}
	else if (str == "while")
	{
		return WHILE;
	}
	else if (str == "do")
	{
		return DO;
	}
	else if (str == "endwh")
	{
		return ENDWH;
	}
	else if (str == "record")
	{
		return RECORD;
	}
	else if (str == "read")
	{
		return READ;
	}
	else if (str == "if")
	{
		return IF;
	}
	else if (str == "then")
	{
		return THEN;
	}
	else if (str == "else")
	{
		return ELSE;
	}
	else if (str == "fi")
	{
		return FI;
	}
	else if (str == "char")
	{
		return CHAR;
	}
	else if (str == "return")
	{
		return RETURN;
	}
	else return ID;
}


Token::LexType Token::BorderLookup(std::string str)
{
	if (str == ";")
	{
		return SEMI;
	}
	else if (str == "=")
	{
		return EQ;
	}
	else if (str == "(")
	{
		return LS;
	}
	else if (str == ")")
	{
		return RS;
	}
	else if (str == "[")
	{
		return LM;
	}
	else if (str == "]")
	{
		return RM;
	}
	else if (str == "+")
	{
		return PLUS;
	}
	else if (str == "-")
	{
		return SUB;
	}
	else if (str == "*")
	{
		return MUL;
	}
	else if (str == "/")
	{
		return DIV;
	}
	else if (str == ".")
	{
		return DOT;
	}
	else if (str == ",")
	{
		return COMMA;
	}
	else if (str == "<")
	{
		return LT;
	}
	else if (str == "\t")
	{
		return TAB;
	}
	else if (str == " ")
	{
		return SPACE;
	}
	else return ENTER;
}


std::string Token::GetLexType()
{
	return GetLexType(m_lexType);
}


std::string Token::GetLexType(const Token::LexType lexType)
{
	switch (lexType)
	{
	case Token::PROGRAM:
		return "PROGRAM";
	case Token::TYPE:
		return "TYPE";
	case Token::INTEGER:
		return "INTEGER";
	case Token::ARRAY:
		return "ARRAY";
	case Token::OF:
		return "OF";
	case Token::VAR:
		return "VAR";
	case Token::PROCEDURE:
		return "PROCEDURE";
	case Token::BEGIN:
		return "BEGIN";
	case Token::WRITE:
		return "WRITE";
	case Token::END:
		return "END";
	case Token::WHILE:
		return "WHILE";
	case Token::DO:
		return "DO";
	case Token::ENDWH:
		return "ENDWH";
	case Token::RECORD:
		return "RECORD";
	case Token::READ:
		return "READ";
	case Token::IF:
		return "IF";
	case Token::THEN:
		return "THEN";
	case Token::ELSE:
		return "ELSE";
	case Token::FI:
		return "FI";
	case Token::CHAR:
		return "CHAR";
	case Token::RETURN:
		return "RETURN";
	case Token::ID:
		return "ID";
	case Token::INTC:
		return "INTC";
	case Token::ASSIGN:
		return "ASSIGN";
	case Token::ARRAYT:
		return "ARRAYT";
	case Token::CHART:
		return "CHART";
	case Token::EOFT:
		return "EOF";
	case Token::SEMI:
		return ";";
	case Token::EQ:
		return "=";
	case Token::LS:
		return "(";
	case Token::RS:
		return ")";
	case Token::LM:
		return "[";
	case Token::RM:
		return "]";
	case Token::PLUS:
		return "+";
	case Token::SUB:
		return "-";
	case Token::MUL:
		return "*";
	case Token::DIV:
		return "/";
	case Token::DOT:
		return ".";
	case Token::COMMA:
		return ",";
	case Token::LT:
		return "<";
	default:
		return std::string();
	}
}