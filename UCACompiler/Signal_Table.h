#pragma once
//各种表的节点声明，声明成一种节点更好么？
enum AccessKind
{
	dir,indir
};
enum IdKind //标识符类型	
{
	typeKind,varKind,procKind
};
enum TypeKind
{
	intTy,charTy,arrayTy,recordTy
};

enum IndexTy      //数组下标类型
{
	inTT,chaRR
};
enum ElemTy        //数组元素类型
{
	chaR,inT
};


struct ParamT          //参数表
{
	std::string idname;
	TypeKind type;
	AccessKind accesskind;
};


class ProcAttr          
{
public:
	int level;
	int size;

	std::list<ParamT> ptable;
	
};

struct VarAttr
{
	AccessKind accesskind;
	int level;
	int off;
	TypeKind realkind;
};

struct Array
{
	TypeKind arraykind;
	int size=0;
};

struct Type           //typekind 内部声明
{
	TypeKind kind;
	Array array;
};
struct Record
{
	Type typet;
};
class RecordT
{
public:
	int size;
	std::list<Record> recordt;
	std::list<Record>::iterator itr;
	void SetNumber();
};
struct AttributeIR
{
	IdKind kind;         //标识符类型
	Type typeattr;
	VarAttr varattr;
	ProcAttr procattr;
	RecordT rec;
	ParamT ptmp;
};
struct ConstNode
{
	std::string idname;
	AttributeIR attributeir;
	int nof;
};
class Signal_Table
{
public:
	Signal_Table();
	~Signal_Table();
	void OutTable(TreeNode * root);
	void Createtable(TreeNode * root);
	void Check(TreeNode * root);
	int SerchArray(std::string idname);
	TypeKind SerchKind(std::string idname);
	int SerchRecord(std::string idname);
	void ShowParam(std::list<ConstNode>::iterator it);
	bool ErrorCheck(TreeNode * root);
	bool ErrorUndefine(TreeNode * root);
	bool CheckId(std::string idname);
	//在扫描声明部分语法树时建立符号表,并检查重定义的语义错误
	//扫描语句部分语法树时查表，检查语义是否声明
private:	
	int offset=7;
	int poffset = 7;
	int level=0;
	std::list<ConstNode> table;
	ConstNode tablenode;
	
	
};

