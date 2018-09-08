#pragma once
class TreeNode
{
	TreeNode *m_parent;
	TreeNode *m_sibling;
	std::list<TreeNode *> m_childList;
public:
	enum NodeType
	{
		ProK,
		PHeadK,
		TypeK,
		VarK,
		ProcK,
		StmLK,
		DecK,
		StmtK,
		ExpK			//¥ÌŒÛ¥¶¿Ì
	};
	enum DecType
	{
		CharK,
		IntegerK,
		ArrayK,
		RecordK,
		IdK
	};
	enum ParamType
	{
		Val,
		Var
	};
	enum StmtType
	{
		IfK,
		WhileK,
		AssignK,
		ReadK,
		WriteK,
		CallK,
		ReturnK
	};
	enum ExpType
	{
		OpK,
		ConstK,
		VariK
	};
	enum ExpVarType
	{
		Id,
		FieldMember,
		ArrayMember
	};
	enum ExpOpType
	{
		LT,
		EQ,
		PLUS,
		MINUS,
		TIMES,
		OVER
	};

	NodeType m_nodeType;
	std::list<std::string> m_IDList;
	DecType m_decType;
	DecType m_decArrayType;
	int m_arrayLow;
	int m_arrayTop;
	ParamType m_paramType;
	std::string m_IdKName;
	StmtType m_stmtType;
	ExpType m_expType;
	ExpVarType m_expVarType;
	ExpOpType m_expOpType;
	int m_expConst;
	int m_lineNumber;

	TreeNode(NodeType nodeType, TreeNode * parent = NULL);
	~TreeNode();

	TreeNode * CreateChild(NodeType nodeType);
	TreeNode * CreateSibling(NodeType nodeType);
	TreeNode * GetChild(const int num);
	TreeNode * GetParent();
	TreeNode * GetSibling();

	std::string GetNodeType();
	std::string GetDecType();
	std::string GetArrayType();
	std::string GetParamType();
	std::string GetStmtType();
	std::string GetExpType();
	std::string GetExpVarType();
	std::string GetExpOpType();

	std::string OutANodeType();
	std::string OutBNodeType();
	std::string OutStmtK();
	std::string OutExpK();
	std::string OutDecK();

	friend std::ostream & operator<<(std::ostream & os, TreeNode * treeNode);
	int GetChildNumber();
	int GetLineNumber();
	void ReParent(TreeNode * parent);
};
std::ostream & operator<<(std::ostream & os, TreeNode * treeNode);
void OutTree(int layer, TreeNode * treeNode);