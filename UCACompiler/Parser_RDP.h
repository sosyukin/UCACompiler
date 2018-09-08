#pragma once

class Parser_RDP
{
public:
	Parser_RDP();
	Parser_RDP(const TokenList &tokenList);
	~Parser_RDP();
	void Out();
	TreeNode * ReturnRoot();
private:
	Token m_token;
	TokenList m_tokenList;
	TreeNode* root;    //with the whole syn tree
	void Match(const Token::LexType lexType);
	
	
	
	void Program();
	void ProgramHead(TreeNode * parent);
	void ProgramName(TreeNode * parent);
	void DeclarePart(TreeNode * parent);
	void TypeDecpart(TreeNode * parent);
	void TypeDec(TreeNode * parent);
	void TypeDecList(TreeNode * parent);
	void TypeDecMore(TreeNode * parent);
	void TypeId(TreeNode * parent);
	void TypeDef(TreeNode * parent);
	void BaseType(TreeNode * parent);
	void StructureType(TreeNode * parent);
	void ArrayType(TreeNode * parent);
	void Low(TreeNode * parent);
	void Top(TreeNode * parent);
	void RecType(TreeNode * parent);
	void FieldDeclist(TreeNode * parent);
	void FieldDecMore(TreeNode * parent);
	void IdList(TreeNode * parent);
	void IdMore(TreeNode * parent);
	void VarDecpart(TreeNode * parent);
	void VarDec(TreeNode * parent);
	void VarDecList(TreeNode * parent);
	void VarDecMore(TreeNode * parent);
	void VarIdList(TreeNode * parent);
	void VarIdMore(TreeNode * parent);
	void ProcDecpart(TreeNode * parent);
	void ProcDec(TreeNode * parent);
	void ProcDecMore(TreeNode * parent);
	void ProcName(TreeNode * parent);
	void ParamList(TreeNode * parent);
	void ParamDecList(TreeNode * parent);
	void ParamMore(TreeNode * parent);
	void Param(TreeNode * parent);
	void FormList(TreeNode * parent);
	void FidMore(TreeNode * parent);
	void ProcDecPart(TreeNode * parent);
	void ProcBody(TreeNode * parent);
	void ProgramBody(TreeNode * parent);
	void StmList(TreeNode * parent);
	void StmMore(TreeNode * parent);
	void Stm(TreeNode * parent);
	void AssCall(TreeNode * parent);
	void AssignmentRest(TreeNode * parent);
	void ConditionalStm(TreeNode * parent);
	void LoopStm(TreeNode * parent);
	void InputStm(TreeNode * parent);
	void Invar(TreeNode * parent);
	void OutputStm(TreeNode * parent);
	void ReturnStm(TreeNode * parent);
	void CallStmRest(TreeNode * parent);
	void ActParamList(TreeNode * parent);
	void ActParamMore(TreeNode * parent);
	void RelExp(TreeNode * parent);
	void OtherRelE(TreeNode * parent);
	void Exp(TreeNode * parent);
	void OtherTerm(TreeNode * parent);
	void Term(TreeNode * parent);
	void OtherFactor(TreeNode * parent);
	void Factor(TreeNode * parent);
	void Variable(TreeNode * parent);
	void VariMore(TreeNode * parent);
	void FieldVar(TreeNode * parent);
	void FieldVarMore(TreeNode * parent);
	void CmpOp(TreeNode * parent);
	void AddOp(TreeNode * parent);
	void MultOp(TreeNode * parent);
	
	//下面是若干的子函数，在这些产生式里加入语法树节点生成和语法错误判断即可
};

