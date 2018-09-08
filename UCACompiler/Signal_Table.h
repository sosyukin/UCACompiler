#pragma once
//���ֱ�Ľڵ�������������һ�ֽڵ����ô��
enum AccessKind
{
	dir,indir
};
enum IdKind //��ʶ������	
{
	typeKind,varKind,procKind
};
enum TypeKind
{
	intTy,charTy,arrayTy,recordTy
};

enum IndexTy      //�����±�����
{
	inTT,chaRR
};
enum ElemTy        //����Ԫ������
{
	chaR,inT
};


struct ParamT          //������
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

struct Type           //typekind �ڲ�����
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
	IdKind kind;         //��ʶ������
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
	//��ɨ�����������﷨��ʱ�������ű�,������ض�����������
	//ɨ����䲿���﷨��ʱ�����������Ƿ�����
private:	
	int offset=7;
	int poffset = 7;
	int level=0;
	std::list<ConstNode> table;
	ConstNode tablenode;
	
	
};

