#include "pch.h"
#include "VNandVT.h"


VNandVT::VNandVT(VN vnt, TreeNode * tnt)
	: isVN(true)
	, tn(tnt)
	, vn(vnt)
{
}


VNandVT::VNandVT(VT vtt, TreeNode * tnt)
	: isVN(false)
	, tn(tnt)
	, vt(vtt)
{
}


VNandVT::~VNandVT()
{
}


void VNandVT::CreateTable(int SYZ[67][39])
{

	int i, j;
	for (i = 0; i < 67; i++)
	{
		for (j = 0; j <39; j++)
		{
			SYZ[i][j] = 0;
		}
	}
	SYZ[Program][VT::PROGRAM] = 1;
	SYZ[ProgramHead][VT::PROGRAM] = 2;
	SYZ[Program][VT::PROGRAM] = 1;

	SYZ[ProgramHead][VT::PROGRAM] = 2;

	SYZ[ProgramName][VT::ID] = 3;

	SYZ[DeclarePart][VT::TYPE] = 4;
	SYZ[DeclarePart][VT::VAR] = 4;
	SYZ[DeclarePart][VT::PROCEDURE] = 4;
	SYZ[DeclarePart][VT::BEGIN] = 4;

	SYZ[TypeDecpart][VT::VAR] = 5;
	SYZ[TypeDecpart][VT::PROCEDURE] = 5;
	SYZ[TypeDecpart][VT::BEGIN] = 5;

	SYZ[TypeDecpart][VT::TYPE] = 6;

	SYZ[TypeDec][VT::TYPE] = 7;

	SYZ[TypeDecList][VT::ID] = 8;

	SYZ[TypeDecMore][VT::VAR] = 9;
	SYZ[TypeDecMore][VT::PROCEDURE] = 9;
	SYZ[TypeDecMore][VT::BEGIN] = 9;


	SYZ[TypeDecMore][VT::ID] = 10;

	SYZ[TypeId][VT::ID] = 11;

	SYZ[TypeDef][VT::INTEGER] = 12;
	SYZ[TypeDef][VT::CHAR] = 12;

	SYZ[TypeDef][VT::ARRAY] = 13;
	SYZ[TypeDef][VT::RECORD] = 13;

	SYZ[TypeDef][VT::ID] = 14;

	SYZ[BaseType][VT::INTEGER] = 15;

	SYZ[BaseType][VT::CHAR] = 16;

	SYZ[StructureType][VT::ARRAY] = 17;

	SYZ[StructureType][VT::RECORD] = 18;

	SYZ[ArrayType][VT::ARRAY] = 19;

	SYZ[Low][VT::INTC] = 20;

	SYZ[Top][VT::INTC] = 21;

	SYZ[RecType][VT::RECORD] = 22;

	SYZ[FieldDecList][VT::INTEGER] = 23;
	SYZ[FieldDecList][VT::CHAR] = 23;

	SYZ[FieldDecList][VT::ARRAY] = 24;

	SYZ[FieldDecMore][VT::END] = 25;

	SYZ[FieldDecMore][VT::INTEGER] = 26;
	SYZ[FieldDecMore][VT::CHAR] = 26;
	SYZ[FieldDecMore][VT::ARRAY] = 26;

	SYZ[IdList][VT::ID] = 27;

	SYZ[IdMore][VT::SEMI] = 28;

	SYZ[IdMore][VT::COMMA] = 29;

	SYZ[VarDecpart][VT::PROCEDURE] = 30;
	SYZ[VarDecpart][VT::BEGIN] = 30;

	SYZ[VarDecpart][VT::VAR] = 31;

	SYZ[VarDec][VT::VAR] = 32;

	SYZ[VarDecList][VT::INTEGER] = 33;
	SYZ[VarDecList][VT::CHAR] = 33;
	SYZ[VarDecList][VT::ARRAY] = 33;
	SYZ[VarDecList][VT::RECORD] = 33;
	SYZ[VarDecList][VT::ID] = 33;

	SYZ[VarDecMore][VT::PROCEDURE] = 34;
	SYZ[VarDecMore][VT::BEGIN] = 34;

	SYZ[VarDecMore][VT::INTEGER] = 35;
	SYZ[VarDecMore][VT::CHAR] = 35;
	SYZ[VarDecMore][VT::ARRAY] = 35;
	SYZ[VarDecMore][VT::RECORD] = 35;
	SYZ[VarDecMore][VT::ID] = 35;

	SYZ[VarIdList][VT::ID] = 36;

	SYZ[VarIdMore][VT::SEMI] = 37;

	SYZ[VarIdMore][VT::COMMA] = 38;

	SYZ[ProcDecpart][VT::BEGIN] = 39;

	SYZ[ProcDecpart][VT::PROCEDURE] = 40;

	SYZ[ProcDec][VT::PROCEDURE] = 41;

	SYZ[ProcDecMore][VT::BEGIN] = 42;

	SYZ[ProcDecMore][VT::PROCEDURE] = 43;

	SYZ[ProcName][VT::ID] = 44;

	SYZ[ParamList][VT::RS] = 45;

	SYZ[ParamList][VT::INTEGER] = 46;
	SYZ[ParamList][VT::CHAR] = 46;
	SYZ[ParamList][VT::ARRAY] = 46;
	SYZ[ParamList][VT::RECORD] = 46;
	SYZ[ParamList][VT::ID] = 46;
	SYZ[ParamList][VT::VAR] = 46;

	SYZ[ParamDecList][VT::INTEGER] = 47;
	SYZ[ParamDecList][VT::CHAR] = 47;
	SYZ[ParamDecList][VT::ARRAY] = 47;
	SYZ[ParamDecList][VT::RECORD] = 47;
	SYZ[ParamDecList][VT::ID] = 47;
	SYZ[ParamDecList][VT::VAR] = 47;

	SYZ[ParamMore][VT::RS] = 48;

	SYZ[ParamMore][VT::SEMI] = 49;

	SYZ[Param][VT::INTEGER] = 50;
	SYZ[Param][VT::CHAR] = 50;
	SYZ[Param][VT::ARRAY] = 50;
	SYZ[Param][VT::RECORD] = 50;
	SYZ[Param][VT::ID] = 50;

	SYZ[Param][VT::VAR] = 51;

	SYZ[FormList][VT::ID] = 52;

	SYZ[FidMore][VT::SEMI] = 53;
	SYZ[FidMore][VT::RS] = 53;

	SYZ[FidMore][VT::COMMA] = 54;

	SYZ[ProcDecPart][VT::TYPE] = 55;
	SYZ[ProcDecPart][VT::VAR] = 55;
	SYZ[ProcDecPart][VT::PROCEDURE] = 55;
	SYZ[ProcDecPart][VT::BEGIN] = 55;

	SYZ[ProcBody][VT::BEGIN] = 56;

	SYZ[ProgramBody][VT::BEGIN] = 57;

	SYZ[StmList][VT::ID] = 58;
	SYZ[StmList][VT::IF] = 58;
	SYZ[StmList][VT::WHILE] = 58;
	SYZ[StmList][VT::RETURN] = 58;
	SYZ[StmList][VT::READ] = 58;
	SYZ[StmList][VT::WRITE] = 58;

	SYZ[StmMore][VT::END] = 59;
	SYZ[StmMore][VT::ENDWH] = 59;
	SYZ[StmMore][VT::ELSE] = 59;
	SYZ[StmMore][VT::FI] = 59;

	SYZ[StmMore][VT::SEMI] = 60;

	SYZ[Stm][VT::IF] = 61;

	SYZ[Stm][VT::WHILE] = 62;

	SYZ[Stm][VT::READ] = 63;

	SYZ[Stm][VT::WRITE] = 64;

	SYZ[Stm][VT::RETURN] = 65;

	SYZ[Stm][VT::ID] = 66;

	SYZ[AssCall][VT::ASSIGN] = 67;
	SYZ[AssCall][VT::LM] = 67;
	SYZ[AssCall][VT::DOT] = 67;


	SYZ[AssCall][VT::LS] = 68;

	SYZ[AssignmentRest][VT::ASSIGN] = 69;
	SYZ[AssignmentRest][VT::LM] = 69;
	SYZ[AssignmentRest][VT::DOT] = 69;

	SYZ[ConditionalStm][VT::IF] = 70;


	SYZ[LoopStm][VT::WHILE] = 71;

	SYZ[InputStm][VT::READ] = 72;

	SYZ[Invar][VT::ID] = 73;

	SYZ[OutputStm][VT::WRITE] = 74;

	SYZ[ReturnStm][VT::RETURN] = 75;

	SYZ[CallStmRest][VT::LS] = 76;

	SYZ[ActParamList][VT::RS] = 77;

	SYZ[ActParamList][VT::ID] = 78;
	SYZ[ActParamList][VT::INTC] = 78;
	SYZ[ActParamList][VT::LS] = 78;

	SYZ[ActParamMore][VT::RS] = 79;

	SYZ[ActParamMore][VT::COMMA] = 80;

	SYZ[RelExp][VT::LS] = 81;
	SYZ[RelExp][VT::INTC] = 81;
	SYZ[RelExp][VT::ID] = 81;

	SYZ[OtherRelE][VT::LT] = 82;
	SYZ[OtherRelE][VT::EQ] = 82;

	SYZ[Exp][VT::LS] = 83;
	SYZ[Exp][VT::INTC] = 83;
	SYZ[Exp][VT::ID] = 83;

	SYZ[OtherTerm][VT::LT] = 84;
	SYZ[OtherTerm][VT::EQ] = 84;
	SYZ[OtherTerm][VT::THEN] = 84;
	SYZ[OtherTerm][VT::DO] = 84;
	SYZ[OtherTerm][VT::RS] = 84;
	SYZ[OtherTerm][VT::END] = 84;
	SYZ[OtherTerm][VT::SEMI] = 84;
	SYZ[OtherTerm][VT::COMMA] = 84;
	SYZ[OtherTerm][VT::ENDWH] = 84;
	SYZ[OtherTerm][VT::ELSE] = 84;
	SYZ[OtherTerm][VT::FI] = 84;
	SYZ[OtherTerm][VT::RM] = 84;


	SYZ[OtherTerm][VT::PLUS] = 85;
	SYZ[OtherTerm][VT::SUB] = 85;

	SYZ[Term][VT::LS] = 86;
	SYZ[Term][VT::INTC] = 86;
	SYZ[Term][VT::ID] = 86;

	SYZ[OtherFactor][VT::PLUS] = 87;
	SYZ[OtherFactor][VT::SUB] = 87;
	SYZ[OtherFactor][VT::LT] = 87;
	SYZ[OtherFactor][VT::EQ] = 87;
	SYZ[OtherFactor][VT::THEN] = 87;
	SYZ[OtherFactor][VT::ELSE] = 87;
	SYZ[OtherFactor][VT::FI] = 87;
	SYZ[OtherFactor][VT::DO] = 87;
	SYZ[OtherFactor][VT::ENDWH] = 87;
	SYZ[OtherFactor][VT::RS] = 87;
	SYZ[OtherFactor][VT::END] = 87;
	SYZ[OtherFactor][VT::SEMI] = 87;
	SYZ[OtherFactor][VT::COMMA] = 87;
	SYZ[OtherFactor][VT::RM] = 87;

	SYZ[OtherFactor][VT::MUL] = 88;
	SYZ[OtherFactor][VT::DIV] = 88;

	SYZ[Factor][VT::LS] = 89;

	SYZ[Factor][VT::INTC] = 90;

	SYZ[Factor][VT::ID] = 91;

	SYZ[Variable][VT::ID] = 92;

	SYZ[VariMore][VT::ASSIGN] = 93;
	SYZ[VariMore][VT::MUL] = 93;
	SYZ[VariMore][VT::DIV] = 93;
	SYZ[VariMore][VT::PLUS] = 93;
	SYZ[VariMore][VT::SUB] = 93;
	SYZ[VariMore][VT::LS] = 93;
	SYZ[VariMore][VT::LT] = 93;
	SYZ[VariMore][VT::EQ] = 93;
	SYZ[VariMore][VT::THEN] = 93;
	SYZ[VariMore][VT::ELSE] = 93;
	SYZ[VariMore][VT::FI] = 93;
	SYZ[VariMore][VT::DO] = 93;
	SYZ[VariMore][VT::ENDWH] = 93;
	SYZ[VariMore][VT::RS] = 93;
	SYZ[VariMore][VT::END] = 93;
	SYZ[VariMore][VT::SEMI] = 93;
	SYZ[VariMore][VT::COMMA] = 93;
	SYZ[VariMore][VT::RM] = 93;

	SYZ[VariMore][VT::LM] = 94;

	SYZ[VariMore][VT::DOT] = 95;

	SYZ[FieldVar][VT::ID] = 96;

	SYZ[FieldVarMore][VT::ASSIGN] = 97;
	SYZ[FieldVarMore][VT::MUL] = 97;
	SYZ[FieldVarMore][VT::DIV] = 97;
	SYZ[FieldVarMore][VT::PLUS] = 97;
	SYZ[FieldVarMore][VT::SUB] = 97;
	SYZ[FieldVarMore][VT::LS] = 97;
	SYZ[FieldVarMore][VT::EQ] = 97;
	SYZ[FieldVarMore][VT::THEN] = 97;
	SYZ[FieldVarMore][VT::ELSE] = 97;
	SYZ[FieldVarMore][VT::FI] = 97;
	SYZ[FieldVarMore][VT::DO] = 97;
	SYZ[FieldVarMore][VT::ENDWH] = 97;
	SYZ[FieldVarMore][VT::RS] = 97;
	SYZ[FieldVarMore][VT::END] = 97;
	SYZ[FieldVarMore][VT::SEMI] = 97;
	SYZ[FieldVarMore][VT::COMMA] = 97;

	SYZ[FieldVarMore][VT::LM] = 98;

	SYZ[CmpOp][VT::LT] = 99;

	SYZ[CmpOp][VT::EQ] = 100;

	SYZ[AddOp][VT::PLUS] = 101;

	SYZ[AddOp][VT::SUB] = 102;

	SYZ[MultOp][VT::MUL] = 103;

	SYZ[MultOp][VT::DIV] = 104;


}

std::ostream & operator<<(std::ostream & os, VNandVT t)
{
	if (t.isVN)
	{
		os << "[VN]" << t.GetVN();
	}
	else os << "[VT]" << Token::GetLexType(t.vt); 
	return os;
}

std::string VNandVT::GetVN()
{
	switch (vn)
	{
	case VNandVT::Program:
		return "Program";
	case VNandVT::ProgramHead:
		return "ProgramHead";
	case VNandVT::ProgramName:
		return "ProgramName";
	case VNandVT::DeclarePart:
		return "DeclarePart";
	case VNandVT::TypeDecpart:
		return "TypeDecpart";
	case VNandVT::TypeDec:
		return "TypeDec";
	case VNandVT::TypeDecList:
		return "TypeDecList";
	case VNandVT::TypeDecMore:
		return "TypeDecMore";
	case VNandVT::TypeId:
		return "TypeId";
	case VNandVT::TypeDef:
		return "TypeDef";
	case VNandVT::BaseType:
		return "BaseType";
	case VNandVT::StructureType:
		return "StructureType";
	case VNandVT::ArrayType:
		return "ArrayType";
	case VNandVT::Low:
		return "Low";
	case VNandVT::Top:
		return "Top";
	case VNandVT::RecType:
		return "RecType";
	case VNandVT::FieldDecList:
		return "FieldDecList";
	case VNandVT::FieldDecMore:
		return "FieldDecMore";
	case VNandVT::IdList:
		return "IdList";
	case VNandVT::IdMore:
		return "IdMore";
	case VNandVT::VarDecpart:
		return "VarDecpart";
	case VNandVT::VarDec:
		return "VarDec";
	case VNandVT::VarDecList:
		return "VarDecList";
	case VNandVT::VarDecMore:
		return "VarDecMore";
	case VNandVT::VarIdList:
		return "VarIdList";
	case VNandVT::VarIdMore:
		return "VarIdMore";
	case VNandVT::ProcDecpart:
		return "ProcDecpart";
	case VNandVT::ProcDec:
		return "ProcDec";
	case VNandVT::ProcDecMore:
		return "ProcDecMore";
	case VNandVT::ProcName:
		return "ProcName";
	case VNandVT::ParamList:
		return "ParamList";
	case VNandVT::ParamDecList:
		return "ParamDecList";
	case VNandVT::ParamMore:
		return "ParamMore";
	case VNandVT::Param:
		return "Param";
	case VNandVT::FormList:
		return "FormList";
	case VNandVT::FidMore:
		return "FidMore";
	case VNandVT::ProcDecPart:
		return "ProcDecPart";
	case VNandVT::ProcBody:
		return "ProcBody";
	case VNandVT::ProgramBody:
		return "ProgramBody";
	case VNandVT::StmList:
		return "StmList";
	case VNandVT::StmMore:
		return "StmMore";
	case VNandVT::Stm:
		return "Stm";
	case VNandVT::AssCall:
		return "AssCall";
	case VNandVT::AssignmentRest:
		return "AssignmentRest";
	case VNandVT::ConditionalStm:
		return "ConditionalStm";
	case VNandVT::LoopStm:
		return "LoopStm";
	case VNandVT::InputStm:
		return "InputStm";
	case VNandVT::Invar:
		return "Invar";
	case VNandVT::OutputStm:
		return "OutputStm";
	case VNandVT::ReturnStm:
		return "ReturnStm";
	case VNandVT::CallStmRest:
		return "CallStmRest";
	case VNandVT::ActParamList:
		return "ActParamList";
	case VNandVT::ActParamMore:
		return "ActParamMore";
	case VNandVT::RelExp:
		return "RelExp";
	case VNandVT::OtherRelE:
		return "OtherRelE";
	case VNandVT::Exp:
		return "Exp";
	case VNandVT::OtherTerm:
		return "OtherTerm";
	case VNandVT::Term:
		return "Term";
	case VNandVT::OtherFactor:
		return "OtherFactor";
	case VNandVT::Factor:
		return "Factor";
	case VNandVT::Variable:
		return "Variable";
	case VNandVT::VariMore:
		return "VariMore";
	case VNandVT::FieldVar:
		return "FieldVar";
	case VNandVT::FieldVarMore:
		return "FieldVarMore";
	case VNandVT::CmpOp:
		return "CmpOp";
	case VNandVT::AddOp:
		return "AddOp";
	case VNandVT::MultOp:
		return "MultOp";
	default:
		return "";
	}
}
void OutStack(std::stack<VNandVT> st)
{
	while (!st.empty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}
}