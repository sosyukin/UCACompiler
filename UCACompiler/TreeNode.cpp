#include "pch.h"
#include "TreeNode.h"

TreeNode::TreeNode(NodeType nodeType, TreeNode * parent)
	: m_nodeType(nodeType)
	, m_parent(parent)
	, m_sibling(NULL)
	, m_lineNumber(0)
{
}


TreeNode::~TreeNode()
{
	//std::cout << "Delete!" << std::endl;
	if (m_sibling)
	{
		delete m_sibling;
	}
	for (std::list<TreeNode *>::iterator i = m_childList.begin(); i != m_childList.end(); i++)
	{
		delete *i;
	}
}


TreeNode * TreeNode::CreateChild(NodeType nodeType)
{
	TreeNode * p = new TreeNode(nodeType, this);
	if (p)
	{
		m_childList.insert(m_childList.end(), p);
	}
	return p;
}


TreeNode * TreeNode::CreateSibling(NodeType nodeType)
{
	TreeNode * p = new TreeNode(nodeType, m_parent);
	if (p)
	{
		m_sibling = p;
	}
	return p;
}


TreeNode * TreeNode::GetChild(const int num)
{
	std::list<TreeNode *>::iterator it = m_childList.begin();
	for (int i = 0; (i < num)&&(it != m_childList.end()); i++)
	{
		it++;
	}
	if (it != m_childList.end())
	{
		return *it;
	}
	else return NULL;
}


TreeNode * TreeNode::GetParent()
{
	return m_parent;
}


TreeNode * TreeNode::GetSibling()
{
	return m_sibling;
}


std::string TreeNode::GetNodeType()
{
	switch (m_nodeType)
	{
	case TreeNode::ProK:
		return "ProK";
	case TreeNode::PHeadK:
		return "PHeadK";
	case TreeNode::TypeK:
		return "TypeK";
	case TreeNode::VarK:
		return "VarK";
	case TreeNode::ProcK:
		return "ProcK";
	case TreeNode::StmLK:
		return "StmLK";
	case TreeNode::DecK:
		return "DecK";
	case TreeNode::StmtK:
		return "StmtK";
	case TreeNode::ExpK:
		return "ExpK";
	default:
		return std::string();
	}
}
std::string TreeNode::GetDecType()
{
	switch (m_decType)
	{
	case TreeNode::ArrayK:
		return "ArrayK";
	case TreeNode::CharK:
		return "CharK";
	case TreeNode::IntegerK:
		return "IntegerK";
	case TreeNode::RecordK:
		return "RecordK";
	case TreeNode::IdK:
		return "IdK";
	default:
		return std::string();
	}
}
std::string TreeNode::GetArrayType()
{
	switch (m_decArrayType)
	{
	case TreeNode::ArrayK:
		return "ArrayK";
	case TreeNode::CharK:
		return "CharK";
	case TreeNode::IntegerK:
		return "IntegerK";
	case TreeNode::RecordK:
		return "RecordK";
	case TreeNode::IdK:
		return "IdK";
	default:
		return std::string();
	}
}
std::string TreeNode::GetParamType()
{
	switch (m_paramType)
	{
	case TreeNode::Val:
		return "Val";
	case TreeNode::Var:
		return "Var";
	default:
		return std::string();
	}
}
std::string TreeNode::GetStmtType()
{
	switch (m_stmtType)
	{
	case TreeNode::IfK:
		return "IfK";
	case TreeNode::WhileK:
		return "WhileK";
	case TreeNode::AssignK:
		return "AssignK";
	case TreeNode::ReadK:
		return "ReadK";
	case TreeNode::WriteK:
		return "WriteK";
	case TreeNode::CallK:
		return "CallK";
	case TreeNode::ReturnK:
		return "ReturnK";
	default:
		return std::string();
	}
}
std::string TreeNode::GetExpType()
{
	switch (m_expType)
	{
	case TreeNode::OpK:
		return "OpK";
	case TreeNode::ConstK:
		return "ConstK";
	case TreeNode::VariK:
		return "VariK";
	default:
		return std::string();
	}
}
std::string TreeNode::GetExpVarType()
{
	switch (m_expVarType)
	{
	case TreeNode::Id:
		return "Id";
	case TreeNode::FieldMember:
		return "FieldMember";
	case TreeNode::ArrayMember:
		return "ArrayMember";
	default:
		return std::string();
	}
}
std::string TreeNode::GetExpOpType()
{
	switch (m_expOpType)
	{
	case TreeNode::LT:
		return "<";
	case TreeNode::EQ:
		return "=";
	case TreeNode::PLUS:
		return "+";
	case TreeNode::MINUS:
		return "-";
	case TreeNode::TIMES:
		return "*";
	case TreeNode::OVER:
		return "/";
	default:
		return std::string();
	}
	
}

std::string TreeNode::OutANodeType()
{
	return GetNodeType();
}
std::string TreeNode::OutBNodeType()
{
	std::string tmp(GetNodeType());
	tmp += " ";
	tmp += *m_IDList.begin();
	return tmp;
}
std::string TreeNode::OutStmtK()
{
	std::string tmp(GetNodeType());
	tmp += " ";
	tmp += GetStmtType();
	return tmp;
}
std::string TreeNode::OutExpK()
{
	stringstream ss;
	std::string tmp(GetNodeType());
	tmp += " ";
	tmp += GetExpType();
	tmp += " ";
	switch (m_expType)
	{
	case TreeNode::OpK:
		tmp += GetExpOpType();
		break;
	case TreeNode::ConstK:
		ss << m_expConst;
		tmp += ss.str();
		break;
	case TreeNode::VariK:
		tmp += GetExpVarType();
		tmp += " ";
		tmp += *m_IDList.begin();
		break;
	default:
		break;
	}
	return tmp;
}
std::string TreeNode::OutDecK()
{
	stringstream ss;
	std::string tmp(GetNodeType());
	tmp += " ";
	if (m_parent->m_nodeType == TreeNode::ProcK)
	{
		tmp += GetParamType();
		tmp += " param: ";
	}
	tmp += GetDecType();
	if (m_decType == TreeNode::ArrayK)
	{
		ss << " " << m_arrayTop << " " << m_arrayLow << " " << GetArrayType();
		tmp += ss.str();
	}
	else if (m_decType == TreeNode::IdK)
	{
		tmp += " ";
		tmp += m_IdKName;
	}
	for (std::list<std::string>::iterator i = m_IDList.begin(); i != m_IDList.end(); i++)
	{
		tmp += " ";
		tmp += *i;
	}
	return tmp;
}

std::ostream & operator<<(std::ostream & os, TreeNode * treeNode)
{
	using namespace std;
	switch (treeNode->m_nodeType)
	{
	case TreeNode::ProK:
	case TreeNode::TypeK:
	case TreeNode::VarK:
	case TreeNode::StmLK:
		os << treeNode->OutANodeType();
		break;
	case TreeNode::PHeadK:
	case TreeNode::ProcK:
		os << treeNode->OutBNodeType();
		break;
	case TreeNode::StmtK:
		os << treeNode->OutStmtK();
		break;
	case TreeNode::DecK:
		os << treeNode->OutDecK();
		break;
	case TreeNode::ExpK:
		os << treeNode->OutExpK();
		break;
	default:
		break;
	}
	return os;
}


int TreeNode::GetChildNumber()
{
	return m_childList.size();
}


int TreeNode::GetLineNumber()
{
	return m_lineNumber;
}


void OutTree(int layer, TreeNode * treeNode)
{
	using namespace std;
	if (treeNode->GetLineNumber() != 0)
	{
		cout << treeNode->GetLineNumber() << ":";
	}
	for (int i = 0; i <= layer; i++)
	{
		cout << "\t";
	}
	cout << treeNode << endl;
	treeNode->m_nodeType;
	for (int i = 0; i < treeNode->GetChildNumber(); i++)
	{
		OutTree(layer + 1, treeNode->GetChild(i));
	}
}


void TreeNode::ReParent(TreeNode * parent)
{
	this->GetParent()->m_childList.remove(this);
	parent->m_childList.insert(parent->m_childList.end(), this);
	this->m_parent = parent;
}
