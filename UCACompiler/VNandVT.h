#pragma once
#include "VNandVT.h"
class VNandVT
{
public:
	enum VN//67
	{
		Program,
		ProgramHead,
		ProgramName,
		DeclarePart,
		TypeDecpart,
		TypeDec,
		TypeDecList,
		TypeDecMore,
		TypeId,
		TypeDef,
		BaseType,
		StructureType,
		ArrayType,
		Low,
		Top,
		RecType,
		FieldDecList,
		FieldDecMore,
		IdList,
		IdMore,
		VarDecpart,
		VarDec,
		VarDecList,
		VarDecMore,
		VarIdList,
		VarIdMore,
		ProcDecpart,
		ProcDec,
		ProcDecMore,
		ProcName,
		ParamList,
		ParamDecList,
		ParamMore,
		Param,
		FormList,
		FidMore,
		ProcDecPart,
		ProcBody,
		ProgramBody,
		StmList,
		StmMore,
		Stm,
		AssCall,
		AssignmentRest,
		ConditionalStm,
		LoopStm,
		InputStm,
		Invar,
		OutputStm,
		ReturnStm,
		CallStmRest,
		ActParamList,
		ActParamMore,
		RelExp,
		OtherRelE,
		Exp,
		OtherTerm,
		Term,
		OtherFactor,
		Factor,
		Variable,
		VariMore,
		FieldVar,
		FieldVarMore,
		CmpOp,
		AddOp,
		MultOp

	};
	typedef Token::LexType VT;
	VNandVT(VN vnt, TreeNode * tnt);
	VNandVT(VT vtt, TreeNode * tnt);
	~VNandVT();
	
	VN vn;
	VT vt;
	TreeNode * tn;
	bool isVN;
	static void CreateTable(int SYZ[67][39]);
	friend std::ostream & operator<<(std::ostream & os, VNandVT t);
	std::string GetVN();
};
std::ostream & operator<<(std::ostream & os, VNandVT t);
void OutStack(std::stack<VNandVT> st);