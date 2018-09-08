#pragma once
class Parser_LL1
{
public:

	Parser_LL1();
	Parser_LL1(const TokenList &tokenList);
	~Parser_LL1();
private:

	std::stack<VNandVT> ap;
	std::stack<TreeNode *> treeStack;
	std::stack<VNandVT::VN> m_VNStack;
	Token m_token;
	TokenList m_tokenList;
	int SYZ[67][39];
	TreeNode * root;
	TreeNode * child;//with the whole syn tree
	TreeNode * parent;

	int Search(VNandVT::VN vn, VNandVT::VT vt);
	void Select(int num) throw(exception);//finish
	void Match(VNandVT::VT vt);//half,need tree

	void Procedure1();
	void Procedure2();
	void Procedure3();
	void Procedure4();
	void Procedure5();
	void Procedure6();
	void Procedure7();
	void Procedure8();
	void Procedure9();
	void Procedure10();
	void Procedure11();
	void Procedure12();
	void Procedure13();
	void Procedure14();
	void Procedure15();
	void Procedure16();
	void Procedure17();
	void Procedure18();
	void Procedure19();
	void Procedure20();
	void Procedure21();
	void Procedure22();
	void Procedure23();
	void Procedure24();
	void Procedure25();
	void Procedure26();
	void Procedure27();
	void Procedure28();
	void Procedure29();
	void Procedure30();
	void Procedure31();
	void Procedure32();
	void Procedure33();
	void Procedure34();
	void Procedure35();
	void Procedure36();
	void Procedure37();
	void Procedure38();
	void Procedure39();
	void Procedure40();
	void Procedure41();
	void Procedure42();
	void Procedure43();
	void Procedure44();
	void Procedure45();
	void Procedure46();
	void Procedure47();
	void Procedure48();
	void Procedure49();
	void Procedure50();
	void Procedure51();
	void Procedure52();
	void Procedure53();
	void Procedure54();
	void Procedure55();
	void Procedure56();
	void Procedure57();
	void Procedure58();
	void Procedure59();
	void Procedure60();
	void Procedure61();
	void Procedure62();
	void Procedure63();
	void Procedure64();
	void Procedure65();
	void Procedure66();
	void Procedure67();
	void Procedure68();
	void Procedure69();
	void Procedure70();
	void Procedure71();
	void Procedure72();
	void Procedure73();
	void Procedure74();
	void Procedure75();
	void Procedure76();
	void Procedure77();
	void Procedure78();
	void Procedure79();
	void Procedure80();
	void Procedure81();
	void Procedure82();
	void Procedure83();
	void Procedure84();
	void Procedure85();
	void Procedure86();
	void Procedure87();
	void Procedure88();
	void Procedure89();
	void Procedure90();
	void Procedure91();
	void Procedure92();
	void Procedure93();
	void Procedure94();
	void Procedure95();
	void Procedure96();
	void Procedure97();
	void Procedure98();
	void Procedure99();
	void Procedure100();
	void Procedure101();
	void Procedure102();
	void Procedure103();
	void Procedure104();

public:
	void Out();
};

