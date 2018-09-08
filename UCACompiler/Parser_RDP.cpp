#include "pch.h"
#include "Parser_RDP.h"
using namespace std;
Parser_RDP::Parser_RDP()
{
}
Parser_RDP::Parser_RDP(const TokenList &tokenList)
{
	//主产生式函数调用（），进入驱动循环
	//出循环，生成了语法树，打印
	m_tokenList = tokenList;
	try
	{
		Program();
	}
	catch (exception e)
	{
		std::cout << "Error" << std::endl;
		std::cout << e.what() << std::endl;
		exit(0);
	}
}
Parser_RDP::~Parser_RDP()
{
}
void Parser_RDP::Out()
{
	OutTree(0, root);
}
//再改一下void Match(const std::string & lexType, const Token & token & nodedata);
//match的功能，检查传入的参数lexType与token的lexType是否一致，不一致返回false，一致则把token中的信息存入Nodedata对应的项里面，返回true;
void Parser_RDP::Match(const Token::LexType lexType) throw(exception)
{
	stringstream ss;
	m_tokenList.ReadToken(m_token);
	if (m_token.m_lexType != lexType)
	{
		std::string exc("Match Error!\n");
		ss << m_token.m_lineNumber << ": Unexcepted Token - " << m_token.GetLexType(lexType) << " but " << m_token.GetLexType();
		exc += ss.str();
		throw exception(exc.c_str());
	}
}
void Parser_RDP::Program()
{
	//Create new tree
	root = new TreeNode(TreeNode::NodeType::ProK);
	//sub function
	ProgramHead(root);
	DeclarePart(root);
	ProgramBody(root);
}
void Parser_RDP::ProgramHead(TreeNode * parent)
{
	Match(Token::PROGRAM);
	TreeNode * node = parent->CreateChild(TreeNode::PHeadK);
	ProgramName(node);
	
}
void Parser_RDP::ProgramName(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.begin(), m_token.m_sem);
}
void Parser_RDP::DeclarePart(TreeNode * parent)
{
	TypeDecpart(parent);
	VarDecpart(parent);
	ProcDecpart(parent);
}
void Parser_RDP::TypeDecpart(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::TYPE)
	{
		TypeDec(parent);
	}
}
void Parser_RDP::TypeDec(TreeNode * parent)
{
	Match(Token::TYPE);
	TreeNode * node = parent->CreateChild(TreeNode::TypeK);
	TypeDecList(node);
}
void Parser_RDP::TypeDecList(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::DecK);
	TypeId(node);
	Match(Token::EQ);
	TypeDef(node);
	Match(Token::SEMI);
	TypeDecMore(parent);
}
void Parser_RDP::TypeDecMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::ID)
		TypeDecList(parent);
	else if (
		m_tokenList.GetToken().m_lexType == Token::PROCEDURE ||
		m_tokenList.GetToken().m_lexType == Token::BEGIN
		)
	{
	}
}
void Parser_RDP::TypeId(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.begin(), m_token.m_sem);
}
void Parser_RDP::TypeDef(TreeNode * parent)
{
	if (
		m_tokenList.GetToken().m_lexType == Token::INTEGER ||
		m_tokenList.GetToken().m_lexType == Token::CHAR
		)
	{
		BaseType(parent);
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::ARRAY ||
		m_tokenList.GetToken().m_lexType == Token::RECORD
		)
	{
		StructureType(parent);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::ID)
	{
		Match(Token::ID);
		parent->m_IdKName = m_token.m_sem;
		parent->m_decType = TreeNode::IdK;
	}
}
void Parser_RDP::BaseType(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::INTEGER)
	{
		Match(Token::INTEGER);
		if (parent->m_decType == TreeNode::ArrayK)
		{
			parent->m_decArrayType = TreeNode::IntegerK;
		}
		else parent->m_decType = TreeNode::IntegerK;
	}
	else if (m_tokenList.GetToken().m_lexType == Token::CHAR)
	{
		Match(Token::CHAR);
		if (parent->m_decType == TreeNode::ArrayK)
		{
			parent->m_decArrayType = TreeNode::CharK;
		}
		parent->m_decType = TreeNode::CharK;
	}
}
void Parser_RDP::StructureType(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::ARRAY)
	{
		ArrayType(parent);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::RECORD)
	{
		RecType(parent);
	}
}
void Parser_RDP::ArrayType(TreeNode * parent)
{
	Match(Token::ARRAY);
	parent->m_decType = TreeNode::ArrayK;
	Match(Token::LM);
	Low(parent);
	Match(Token::DOT);
	Match(Token::DOT);
	Top(parent);
	Match(Token::RM);
	Match(Token::OF);
	BaseType(parent);
}
void Parser_RDP::Low(TreeNode * parent)
{
	stringstream ss;
	Match(Token::INTC);
	ss << m_token.m_sem;
	ss >> parent->m_arrayLow;
}
void Parser_RDP::Top(TreeNode * parent)
{
	stringstream ss;
	Match(Token::INTC);
	ss << m_token.m_sem;
	ss >> parent->m_arrayLow;
}
void Parser_RDP::RecType(TreeNode * parent)
{
	Match(Token::RECORD);
	parent->m_decType = TreeNode::RecordK;
	FieldDeclist(parent);
	Match(Token::END);
}
void Parser_RDP::FieldDeclist(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::DecK);
	BaseType(node);
	IdList(node);
	Match(Token::SEMI);
	FieldDecMore(parent);
}
void Parser_RDP::FieldDecMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::END)
	{
		//kong
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::INTEGER ||
		m_tokenList.GetToken().m_lexType == Token::CHAR ||
		m_tokenList.GetToken().m_lexType == Token::ARRAY
		)
	{
		FieldDeclist(parent);
	}
}
void Parser_RDP::IdList(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.end(), m_token.m_sem);
	IdMore(parent);
}
void Parser_RDP::IdMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::SEMI)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::COMMA)
	{
		Match(Token::SEMI);
		IdList(parent);
	}
}
void Parser_RDP::VarDecpart(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::PROCEDURE ||
		m_tokenList.GetToken().m_lexType == Token::BEGIN
		)
	{
		//KONG
	}
	else if (m_tokenList.GetToken().m_lexType == Token::VAR)
	{
		VarDec(parent);
	}
}
void Parser_RDP::VarDec(TreeNode * parent)
{
	Match(Token::VAR);
	TreeNode * node = parent->CreateChild(TreeNode::VarK);
	VarDecList(node);
}
void Parser_RDP::VarDecList(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::DecK);
	TypeDef(node);
	VarIdList(node);
	Match(Token::SEMI);
	VarDecMore(parent);
}
void Parser_RDP::VarDecMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::PROCEDURE ||
		m_tokenList.GetToken().m_lexType == Token::BEGIN
		)
	{
		//kong
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::INTEGER ||
		m_tokenList.GetToken().m_lexType == Token::CHAR ||
		m_tokenList.GetToken().m_lexType == Token::ARRAY ||
		m_tokenList.GetToken().m_lexType == Token::RECORD ||
		m_tokenList.GetToken().m_lexType == Token::ID
		)
	{
		VarDecList(parent);
	}
}
void Parser_RDP::VarIdList(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.end(), m_token.m_sem);
	VarIdMore(parent);
}
void Parser_RDP::VarIdMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::SEMI)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::COMMA)
	{
		Match(Token::COMMA);
		VarIdList(parent);
	}
}
void Parser_RDP::ProcDecpart(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::BEGIN)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::PROCEDURE)
	{
		ProcDec(parent);
	}
}
void Parser_RDP::ProcDec(TreeNode * parent)
{
	Match(Token::PROCEDURE);
	TreeNode * node = parent->CreateChild(TreeNode::ProcK);
	ProcName(node);
	Match(Token::LS);
	ParamList(node);
	Match(Token::RS);
	Match(Token::SEMI);
	ProcDecPart(node);
	ProcBody(node);
	ProcDecMore(parent);
}
void Parser_RDP::ProcDecMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::BEGIN)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::PROCEDURE)
	{
		ProcDec(parent);
	}
}
void Parser_RDP::ProcName(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.begin(), m_token.m_sem);
}
void Parser_RDP::ParamList(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::RS)
	{
		//kong
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::INTEGER ||
		m_tokenList.GetToken().m_lexType == Token::CHAR ||
		m_tokenList.GetToken().m_lexType == Token::ARRAY ||
		m_tokenList.GetToken().m_lexType == Token::RECORD ||
		m_tokenList.GetToken().m_lexType == Token::ID ||
		m_tokenList.GetToken().m_lexType == Token::VAR
		)
	{
		ParamDecList(parent);
	}
}
void Parser_RDP::ParamDecList(TreeNode * parent)
{
	Param(parent);
	ParamMore(parent);
}
void Parser_RDP::ParamMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::LS)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::SEMI)
	{
		Match(Token::SEMI);
		ParamDecList(parent);
	}
}
void Parser_RDP::Param(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::VAR)
	{
		Match(Token::VAR);
		TreeNode * node = parent->CreateChild(TreeNode::DecK);
		node->m_paramType = TreeNode::Var;
		TypeDef(node);
		FormList(node);
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::INTEGER ||
		m_tokenList.GetToken().m_lexType == Token::CHAR ||
		m_tokenList.GetToken().m_lexType == Token::ARRAY ||
		m_tokenList.GetToken().m_lexType == Token::RECORD ||
		m_tokenList.GetToken().m_lexType == Token::ID
		)
	{
		TreeNode * node = parent->CreateChild(TreeNode::DecK);
		node->m_paramType = TreeNode::Val;
		TypeDef(node);
		FormList(node);
	}
}
void Parser_RDP::FormList(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_IDList.insert(parent->m_IDList.end(), m_token.m_sem);
	FidMore(parent);
}
void Parser_RDP::FidMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::SEMI || m_tokenList.GetToken().m_lexType == Token::RS)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::COMMA)
	{
		Match(Token::COMMA);
		FormList(parent);
	}
}
void Parser_RDP::ProcDecPart(TreeNode * parent)
{
	DeclarePart(parent);
}
void Parser_RDP::ProcBody(TreeNode * parent)
{
	ProgramBody(parent);
}
void Parser_RDP::ProgramBody(TreeNode * parent)
{
	Match(Token::BEGIN);
	TreeNode * node = parent->CreateChild(TreeNode::StmLK);
	StmList(node);
	Match(Token::END);
}
void Parser_RDP::StmList(TreeNode * parent)
{
	Stm(parent);
	StmMore(parent);
}
void Parser_RDP::StmMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::ELSE || m_tokenList.GetToken().m_lexType == Token::FI || m_tokenList.GetToken().m_lexType == Token::END || m_tokenList.GetToken().m_lexType == Token::ENDWH)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::SEMI)
	{
		Match(Token::SEMI);
		StmList(parent);
	}
}
void Parser_RDP::Stm(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::StmtK);
	if (m_tokenList.GetToken().m_lexType == Token::IF)
	{
		ConditionalStm(node);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::WHILE)
	{
		LoopStm(node);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::READ)
	{
		InputStm(node);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::WRITE)
	{
		OutputStm(node);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::RETURN)
	{
		ReturnStm(node);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::ID)
	{
		Match(Token::ID);
		TreeNode * node1 = node->CreateChild(TreeNode::ExpK);
		node1->m_expType = TreeNode::VariK;
		node1->m_IDList.insert(node1->m_IDList.begin(), m_token.m_sem);
		AssCall(node1);
	}
}
void Parser_RDP::AssCall(TreeNode * parent)
{
	if (
		m_tokenList.GetToken().m_lexType == Token::ASSIGN ||
		m_tokenList.GetToken().m_lexType == Token::LM ||
		m_tokenList.GetToken().m_lexType == Token::DOT
		)
	{
		AssignmentRest(parent);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::LS)
	{
		CallStmRest(parent->GetParent());
	}
}
void Parser_RDP::AssignmentRest(TreeNode * parent)
{
	VariMore(parent);
	Match(Token::ASSIGN);
	parent->GetParent()->m_stmtType = TreeNode::AssignK;
	Exp(parent->GetParent());
}
void Parser_RDP::ConditionalStm(TreeNode * parent)
{
	Match(Token::IF);
	parent->m_stmtType = TreeNode::IfK;
	RelExp(parent);
	Match(Token::THEN);
	StmList(parent);
	Match(Token::ELSE);
	StmList(parent);
	Match(Token::FI);
}
void Parser_RDP::LoopStm(TreeNode * parent)
{
	Match(Token::WHILE);
	parent->m_stmtType = TreeNode::WhileK;
	RelExp(parent);
	Match(Token::DO);
	StmList(parent);
	Match(Token::ENDWH);
}
void Parser_RDP::InputStm(TreeNode * parent)
{
	Match(Token::READ);
	parent->m_stmtType = TreeNode::ReadK;
	Match(Token::LS);
	Invar(parent);
	Match(Token::RS);
}
void Parser_RDP::Invar(TreeNode * parent)
{
	Match(Token::ID);
	TreeNode * node = parent->CreateChild(TreeNode::ExpK);
	node->m_expType = TreeNode::VariK;
	node->m_expVarType = TreeNode::Id;
	node->m_IDList.insert(node->m_IDList.begin(), m_token.m_sem);
}
void Parser_RDP::OutputStm(TreeNode * parent)
{
	Match(Token::WRITE);
	parent->m_stmtType = TreeNode::WriteK;
	Match(Token::LS);
	Invar(parent);
	Match(Token::RS);
}
void Parser_RDP::ReturnStm(TreeNode * parent)
{
	Match(Token::RETURN);
	parent->m_stmtType = TreeNode::ReturnK;
}
void Parser_RDP::CallStmRest(TreeNode * parent)
{
	Match(Token::LS);
	parent->m_stmtType = TreeNode::CallK;
	ActParamList(parent);
	Match(Token::RS);
}
void Parser_RDP::ActParamList(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::RS)
	{
		//kong
	}
	else if (
		m_tokenList.GetToken().m_lexType == Token::LS ||
		m_tokenList.GetToken().m_lexType == Token::INTC ||
		m_tokenList.GetToken().m_lexType == Token::ID
		)
	{
		Exp(parent);
		ActParamMore(parent);
	}
}
void Parser_RDP::ActParamMore(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::RS)
	{
		//kong
	}
	else if (m_tokenList.GetToken().m_lexType == Token::COMMA)
	{
		Match(Token::COMMA);
		ActParamList(parent);
	}
}
void Parser_RDP::RelExp(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::ExpK);
	Exp(node);
	OtherRelE(node);
}
void Parser_RDP::OtherRelE(TreeNode * parent)
{
	CmpOp(parent);
	Exp(parent);
}
void Parser_RDP::Exp(TreeNode * parent)
{
	TreeNode * node = parent->CreateChild(TreeNode::ExpK);
	Term(node);
	OtherTerm(node);
}
void Parser_RDP::OtherTerm(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::LT ||
		m_tokenList.GetToken().m_lexType == Token::EQ ||
		m_tokenList.GetToken().m_lexType == Token::RM ||
		m_tokenList.GetToken().m_lexType == Token::THEN ||
		m_tokenList.GetToken().m_lexType == Token::ELSE ||
		m_tokenList.GetToken().m_lexType == Token::FI ||
		m_tokenList.GetToken().m_lexType == Token::DO ||
		m_tokenList.GetToken().m_lexType == Token::ENDWH ||
		m_tokenList.GetToken().m_lexType == Token::END ||
		m_tokenList.GetToken().m_lexType == Token::SEMI ||
		m_tokenList.GetToken().m_lexType == Token::COMMA
		)
	{
		//KONG
	}
	else if (m_tokenList.GetToken().m_lexType == Token::PLUS ||
		m_tokenList.GetToken().m_lexType == Token::SUB)
	{
		AddOp(parent);
		Exp(parent);
	}
}
void Parser_RDP::Term(TreeNode * parent)
{
	Factor(parent);
	OtherFactor(parent);
}
void Parser_RDP::OtherFactor(TreeNode * parent)
{
	if (
		m_tokenList.GetToken().m_lexType == Token::LT ||
		m_tokenList.GetToken().m_lexType == Token::EQ ||
		m_tokenList.GetToken().m_lexType == Token::RM ||
		m_tokenList.GetToken().m_lexType == Token::THEN ||
		m_tokenList.GetToken().m_lexType == Token::ELSE ||
		m_tokenList.GetToken().m_lexType == Token::FI ||
		m_tokenList.GetToken().m_lexType == Token::DO ||
		m_tokenList.GetToken().m_lexType == Token::ENDWH ||
		m_tokenList.GetToken().m_lexType == Token::END ||
		m_tokenList.GetToken().m_lexType == Token::SEMI ||
		m_tokenList.GetToken().m_lexType == Token::COMMA ||
		m_tokenList.GetToken().m_lexType == Token::PLUS ||
		m_tokenList.GetToken().m_lexType == Token::SUB
		)
	{
		//KONG
	}
	else if (m_tokenList.GetToken().m_lexType == Token::MUL ||
		m_tokenList.GetToken().m_lexType == Token::DIV
		)
	{
		MultOp(parent);
		Term(parent);
	}
}
void Parser_RDP::Factor(TreeNode * parent)
{
	stringstream ss;
	if (m_tokenList.GetToken().m_lexType == Token::LS)
	{
		Match(Token::LS);
		Exp(parent);
		Match(Token::RS);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::INTC)
	{
		
		Match(Token::INTC);
		parent->m_expType = TreeNode::ConstK;
		ss << m_token.m_sem;
		ss >> parent->m_expConst;
	}
	else if (m_tokenList.GetToken().m_lexType == Token::ID)
	{
		Variable(parent);
	}
}
void Parser_RDP::Variable(TreeNode * parent)
{
	Match(Token::ID);
	parent->m_expType = TreeNode::VariK;
	parent->m_IDList.insert(parent->m_IDList.begin(), m_token.m_sem);
	VariMore(parent);
}
void Parser_RDP::VariMore(TreeNode * parent)
{
	if (
		m_tokenList.GetToken().m_lexType == Token::LT ||
		m_tokenList.GetToken().m_lexType == Token::EQ ||
		m_tokenList.GetToken().m_lexType == Token::RM ||
		m_tokenList.GetToken().m_lexType == Token::THEN ||
		m_tokenList.GetToken().m_lexType == Token::ELSE ||
		m_tokenList.GetToken().m_lexType == Token::FI ||
		m_tokenList.GetToken().m_lexType == Token::DO ||
		m_tokenList.GetToken().m_lexType == Token::ENDWH ||
		m_tokenList.GetToken().m_lexType == Token::END ||
		m_tokenList.GetToken().m_lexType == Token::SEMI ||
		m_tokenList.GetToken().m_lexType == Token::COMMA ||
		m_tokenList.GetToken().m_lexType == Token::PLUS ||
		m_tokenList.GetToken().m_lexType == Token::SUB ||
		m_tokenList.GetToken().m_lexType == Token::MUL ||
		m_tokenList.GetToken().m_lexType == Token::DIV ||
		m_tokenList.GetToken().m_lexType == Token::ASSIGN
		)
	{
		//KONG
	}
	else if (m_tokenList.GetToken().m_lexType == Token::LM)
	{
		Match(Token::LM);
		parent->m_expVarType = TreeNode::ArrayMember;
		Exp(parent);
		Match(Token::RM);
	}
	else if (m_tokenList.GetToken().m_lexType == Token::DOT)
	{
		Match(Token::DOT);
		parent->m_expVarType = TreeNode::FieldMember;
		FieldVar(parent);
	}
}
void Parser_RDP::FieldVar(TreeNode * parent)
{
	Match(Token::ID);
	TreeNode * node = parent->CreateChild(TreeNode::ExpK);
	node->m_expType = TreeNode::VariK;
	node->m_IDList.insert(node->m_IDList.begin(), m_token.m_sem);
	//FieldVarMore(parent);
}
void Parser_RDP::CmpOp(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::LT)
	{
		Match(Token::LT);
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::LT;
	}
	else if (m_tokenList.GetToken().m_lexType == Token::EQ)
	{
		Match(Token::EQ);
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::EQ;
	}
}
void Parser_RDP::AddOp(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::PLUS)
	{
		Match(Token::PLUS);
		TreeNode * node = parent->CreateChild(TreeNode::ExpK);
		node->m_expType = parent->m_expType;
		if (node->m_expType == TreeNode::ConstK)
		{
			node->m_expConst = parent->m_expConst;
		}
		else if (node->m_expType == TreeNode::VariK)
		{
			node->m_IDList = parent->m_IDList;
		}
		else if (node->m_expType == TreeNode::OpK)
		{
		}
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::PLUS;
	}
	else if (m_tokenList.GetToken().m_lexType == Token::SUB)
	{
		Match(Token::SUB);
		TreeNode * node = parent->CreateChild(TreeNode::ExpK);
		node->m_expType = parent->m_expType;
		if (node->m_expType == TreeNode::ConstK)
		{
			node->m_expConst = parent->m_expConst;
		}
		else if (node->m_expType == TreeNode::VariK)
		{
			node->m_IDList = parent->m_IDList;
		}
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::MINUS;
	}
}
void Parser_RDP::MultOp(TreeNode * parent)
{
	if (m_tokenList.GetToken().m_lexType == Token::MUL)
	{
		Match(Token::MUL);
		TreeNode * node = parent->CreateChild(TreeNode::ExpK);
		node->m_expType = parent->m_expType;
		if (node->m_expType == TreeNode::ConstK)
		{
			node->m_expConst = parent->m_expConst;
		}
		else if (node->m_expType == TreeNode::VariK)
		{
			node->m_IDList = parent->m_IDList;
		}
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::TIMES;
	}
	else if (m_tokenList.GetToken().m_lexType == Token::DIV)
	{
		Match(Token::DIV);
		TreeNode * node = parent->CreateChild(TreeNode::ExpK);
		node->m_expType = parent->m_expType;
		if (node->m_expType == TreeNode::ConstK)
		{
			node->m_expConst = parent->m_expConst;
		}
		else if (node->m_expType == TreeNode::VariK)
		{
			node->m_IDList = parent->m_IDList;
		}
		parent->m_expType = TreeNode::OpK;
		parent->m_expOpType = TreeNode::OVER;
	}
}
void Parser_RDP::FieldVarMore(TreeNode * parent)
{
	Match(Token::LM);
	Exp(parent);
	Match(Token::RM);
}
TreeNode * Parser_RDP::ReturnRoot()
{
	return root;
}