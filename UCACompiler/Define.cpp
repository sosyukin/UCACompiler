#include "pch.h"
using namespace std;
bool Match(std::string str)
{
	return false;
}
void Program()
{
	ProgramHead();
	DeclarePart();
	ProgramBody();
}
void ProgramHead()
{
	Match("PROGRAM");
	ProgramName();
}
void ProgramName()
{
	Match("ID");
}
void DeclarePart()
{
	TypeDecpart();
	VarDecpart();
	ProcDecPart();
}
void TypeDecpart()
{
	//kong
}
void TypeDec()
{
	Match("TYPE");
	TypeDecList();
}
void TypeDecList()
{
	TypeId();
	Match("=");
	TypeDef();
	Match(";");
	TypeDecMore();
}
void TypeDecMore()
{
	string token;
	if (token=="ID")
	{
		TypeDecList();
	}
	else if (token == "PROCDURE" || token == "BEGIN")
	{
		//kong
	}
}
void TypeId()
{
	Match("ID");
}
void TypeDef()
{
	string token;
	if (token == "INTEGER" || token == "CHAR")
	{
		BaseType();
	}
	else if (token == "ARRAY" || token == "RECORD")
	{
		StructureType();
	}
	else if (token=="ID")
	{
		Match("ID");
	}
}
void BaseType()
{
	string token;
	if (token == "INTEGER")
	{
		Match("INTEGER");
	}
	else if (token == "CHAR")
	{
		Match("CHAR");
	}
}
void StructureType()
{
	string token;
	if (token == "ARRAY")
	{
		ArrayType();
	}
	else if (token=="RECORD")
	{
		RecType();

	}
}
void ArrayType()
{
	Match("ARRAY");
	Match("[");
	Low();
	Match(".");
	Match(".");
	Top();
	Match("]");
	Match("OF");
	BaseType();
}
void Low()
{
	Match("INTC");
}
void Top()
{
	Match("INTC");
}
void RecType()
{
	Match("RECORD");
	FieldDeclist();
	Match("END");
}
void FieldDeclist()
{
	BaseType();
	IdList();
	Match(";");
	FieldDecMore();
}
void FieldDecMore()
{
	string token;
	if (token=="END")
	{
		//kong
	}
	else if (token=="INTTEGER"||token=="CHAR"||token=="ARRAY")
	{
		FieldDeclist();
	}
}
void IdList()
{
	Match("ID");
	IdMore();

}
void IdMore()
{
	string token;
	if (token == ";")
	{
		//kong
	}
	else if (token == "COMMA")
	{
		Match(";");
		IdList();
	}
}
void VarDecpart()
{
	string token;
	if (token == "PROCEDURE" || token == "BEGIN")
	{
		//KONG
	}
	else if (token=="VAR")
	{
		VarDec();
	}
}
void VarDec()
{
	Match("VAR");
	VarDecList();
}
void VarDecList()
{
	TypeDef();
	VarIdList();
	Match(";");
	VarDecMore();
}
void VarDecMore()
{
	string token;
	if (token == "PROCDURE" || token == "BEGIN")
	{
		//kong
	}
	else if (token == "INTEGER" || token == "CHAR" || token == "ARRAY" || token == "RECORD"|| token == "ID")
	{
		VarDecList();
	}
}
void VarIdList()
{
	Match("ID");
	VarIdMore();
}
void VarIdMore()
{
	string token;
	if (token == ";")
	{
		//kong
	}
	else if (token=="COMMA")
	{
		VarIdList();
	}
}
void ProcDecpart()
{
	string token;
	if (token == "BEGIN")
	{
		//kong
	}
	else if (token == "PROCDURE")
	{
		ProcDec();
	}
}
void ProcDec()
{
	Match("PROCEDURE");
	ProcName();
	Match("(");
	ParamList();
	Match(")");
	Match(";");
	ProcDecPart();
	ProcBody();
	ProcDecMore();
}
void ProcDecMore()
{
	string token;
	if (token == "BEGIN")
	{
		//kong
	}
	else if (token == "PROCDURE")
	{
		ProcDec();
	}
}
void ProcName()
{
	Match("ID");
}
void ParamList()
{
	string token;
	if (token == ")")
	{
		//kong
	}
	else if (token == "INTEGER" || token == "CHAR" || token == "ARRAY" || token == "RECORD" || token == "ID"||token=="VAR")
	{
		ParamDecList();
	}
}
void ParamDecList()
{
	Param();
	ParamMore();
}
void ParamMore()
{
	string token;
	if (token == "(")
	{
		//kong
	}
	else if (token == ";")
	{
		ParamDecList();
	}
}
void Param()
{
	string token;
	if (token == "VAR")
	{
		Match("VAR");
		TypeDef();
		FormList();
	}
	else if (token == "INTEGER" || token == "CHAR" || token == "ARRAY" || token == "RECORD" || token == "ID" )
	{
		TypeDef();
		FormList();
	}
}
void FormList()
{
	Match("ID");
	FidMore();
}
void FidMore()
{
	string token;
	if (token == ";" || token == "," || token == ")")
	{
		//kong
	}
	else if (token == "COMMA")
	{
		Match(",");
		FormList();
	}
}
void ProcDecPart()
{
	DeclarePart();
}
void ProcBody()
{
	ProgramBody();
}
void ProgramBody()
{
	Match("BEGIN");
	StmList();
	Match("END");
}
void StmList()
{
	Stm();
	StmMore();
}
void StmMore()
{
	string token;
	if (token == "ELSE" || token == "FI" || token == "END" || token == "ENDWH")
	{
		//kong
	}
	else if (token == ";")
	{
		Match(";");
		StmList();
	}
}
void Stm()
{
	string token;
	if (token == "IF")
	{
		ConditionalStm();

	}
	else if (token == "WHILE")
	{
		LoopStm();
	}
	else if (token == "READ")
	{
		InputStm();
	}
	else if (token == "WRITE")
	{
		OutputStm();
	}
	else if (token == "RETURN")
	{
		ReturnStm();
	}
	else if (token == "ID")
	{
		Match("ID");
		AssCall();
	}
}
void AssCall()
{
	string token;
	if (token == ":=")
	{
		AssignmentRest();

	}
	else if (token == "(")
	{
		CallStmRest();
	}
}
void AssignmentRest()
{
	VariMore();
	Match(":=");
	Exp();
}
void ConditionalStm()
{
	Match("IF");
	RelExp();
	Match("THEN");
	StmList();
	Match("ELSE");
	StmList();
	Match("FI");
}
void LoopStm()
{
	Match("WHILE");
	RelExp();
	Match("DO");
	StmList();
	Match("ENDWH");
}
void InputStm()
{
	Match("READ");
	Match("(");
	Invar();
	Match(")");
}
void Invar()
{
	Match("ID");
}
void OutputStm()
{
	Match("WRITE");
}
void ReturnStm()
{
	Match("RETURN");
}
void CallStmRest()
{
	Match("(");
	ActParamList();
}
void ActParamList()
{
	string token;
	if (token == ")")
	{
		//kong

	}
	else if (token == "(" || token == "INTC" || token == "ID")
	{
		Exp();
		ActParamMore();
	}
}
void ActParamMore()
{
	string token;
	if (token == ")")
	{
		//kong

	}
	else if (token == "COMMA")
	{
		ActParamList();
	}
}
void RelExp()
{
	Exp();
	OtherRelE();
}
void OtherRelE()
{
	CmpOp();
	Exp();
}
void Exp()
{
	Term();
	OtherTerm();

}
void OtherTerm()
{
	string token;
	if (token == "<" || token == "=" || token == "]" || token == "THEN" || token == "ELSE" || token == "FI" || token == "DO" || token == "ENDWH" || token == "END" || token == ";" || token == "COMMA")
	{
		//KONG
	}
	else if (token == "+" || token == "-")
	{
		AddOp();
		Exp();
	}
}
void Term()
{
	Factor();
	OtherFactor();
}
void OtherFactor()
{
	string token;
	if (token == "<" || token == "=" || token == "]" || token == "THEN" || token == "ELSE" || token == "FI" || token == "DO" || token == "ENDWH" || token == "END" || token == ";" || token == "COMMA" || token == "+" || token == "-")
	{
		//KONG
	}
	else if (token == "*" || token == "/")
	{
		
		MultOp();
		Term();
	}
}
void Factor()
{
	string token;
	if (token == "(")
	{
		Match("(");
		Exp();
		Match(")");
	}
	else if (token == "INTC")
	{
		Match("INTC");
	}
	else if (token == "ID")
	{
		Variable();

	}
	
}
void Variable()
{
	Match("ID");
	VariMore();
}
void VariMore()
{
	string token;
	if (token == "<" || token == "=" || token == "]" || token == "THEN" || token == "ELSE" || token == "FI" || token == "DO" || token == "ENDWH" || token == "END" || token == ";" || token == "COMMA" || token == "+" || token == "-" || token == "*" || token == "/" || token == ":=")
	{
		//KONG
	}
	else if (token == "[" )
	{

		Match("[");
		Exp();
		Match("]");
	}
	else if (token=="DOT")
	{
		Match(".");
		FieldVar();
	}
}
void FieldVar()
{
	Match("ID");
	FieldVarMore();
}
void FieldVarMore()
{
	Match("[");
	Exp();
	Match("]");
}
void CmpOp()
{
	string token;
	if (token == "<")
	{
		Match("<");
	}
	else if (token == "=")
	{
		Match("=");
	}
}
void AddOp()
{
	string token;
	if (token == "+")
	{
		Match("+");
	}
	else if (token == "-")
	{
		Match("-");
	}
}
void MultOp()
{
	string token;
	if (token == "*")
	{
		Match("*");
	}
	else if (token == "/")
	{
		Match("/");
	}
}