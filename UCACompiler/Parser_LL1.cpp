#include "pch.h"
#include "Parser_LL1.h"

Parser_LL1::Parser_LL1()
{
}
Parser_LL1::Parser_LL1(const TokenList &tokenList)
{
	VNandVT::CreateTable(SYZ);
	m_tokenList = tokenList;
	ap.push(VNandVT(VNandVT::Program, root));
	try
	{
		while (!m_tokenList.Empty() && !ap.empty())
		{
			//m_token = m_tokenList.GetToken();
			//m_token.Out();
			//OutStack(ap);
			//cin.get();
			if (!ap.top().isVN)
			{
				Match(ap.top().vt);
			}
			else if (ap.top().isVN)
			{
				m_token = m_tokenList.GetToken();
				Select(Search(ap.top().vn, m_token.m_lexType));
			}
		}
		if (m_tokenList.Empty())
		{
			throw exception("Cannot get other token!");
		}
	}
	catch (exception e)
	{
		std::cout << e.what() << std::endl;
	}
}
Parser_LL1::~Parser_LL1()
{
}
int Parser_LL1::Search(VNandVT::VN vn, VNandVT::VT vt)
{
	return SYZ[vn][vt];
}
void Parser_LL1::Select(int num) throw (exception)
{
	//std::cout << "Procedure #" << num << std::endl;
	switch (num)
	{
	case 1: Procedure1();break;
	case 2: Procedure2();break;
	case 3: Procedure3();break;
	case 4: Procedure4();break;
	case 5: Procedure5();break;
	case 6: Procedure6();break;
	case 7: Procedure7();break;
	case 8: Procedure8();break;
	case 9: Procedure9();break;
	case 10: Procedure10();break;
	case 11: Procedure11();break;
	case 12: Procedure12();break;
	case 13: Procedure13();break;
	case 14: Procedure14();break;
	case 15: Procedure15();break;
	case 16: Procedure16();break;
	case 17: Procedure17();break;
	case 18: Procedure18();break;
	case 19: Procedure19();break;
	case 20: Procedure20();break;
	case 21: Procedure21();break;
	case 22: Procedure22();break;
	case 23: Procedure23();break;
	case 24: Procedure24();break;
	case 25: Procedure25();break;
	case 26: Procedure26();break;
	case 27: Procedure27();break;
	case 28: Procedure28();break;
	case 29: Procedure29();break;
	case 30: Procedure30();break;
	case 31: Procedure31();break;
	case 32: Procedure32();break;
	case 33: Procedure33();break;
	case 34: Procedure34();break;
	case 35: Procedure35();break;
	case 36: Procedure36();break;
	case 37: Procedure37();break;
	case 38: Procedure38();break;
	case 39: Procedure39();break;
	case 40: Procedure40();break;
	case 41: Procedure41();break;
	case 42: Procedure42();break;
	case 43: Procedure43();break;
	case 44: Procedure44();break;
	case 45: Procedure45();break;
	case 46: Procedure46();break;
	case 47: Procedure47();break;
	case 48: Procedure48();break;
	case 49: Procedure49();break;
	case 50: Procedure50();break;
	case 51: Procedure51();break;
	case 52: Procedure52();break;
	case 53: Procedure53();break;
	case 54: Procedure54();break;
	case 55: Procedure55();break;
	case 56: Procedure56();break;
	case 57: Procedure57();break;
	case 58: Procedure58();break;
	case 59: Procedure59();break;
	case 60: Procedure60();break;
	case 61: Procedure61();break;
	case 62: Procedure62();break;
	case 63: Procedure63();break;
	case 64: Procedure64();break;
	case 65: Procedure65();break;
	case 66: Procedure66();break;
	case 67: Procedure67();break;
	case 68: Procedure68();break;
	case 69: Procedure69();break;
	case 70: Procedure70();break;
	case 71: Procedure71();break;
	case 72: Procedure72();break;
	case 73: Procedure73();break;
	case 74: Procedure74();break;
	case 75: Procedure75();break;
	case 76: Procedure76();break;
	case 77: Procedure77();break;
	case 78: Procedure78();break;
	case 79: Procedure79();break;
	case 80: Procedure80();break;
	case 81: Procedure81();break;
	case 82: Procedure82();break;
	case 83: Procedure83();break;
	case 84: Procedure84();break;
	case 85: Procedure85();break;
	case 86: Procedure86();break;
	case 87: Procedure87();break;
	case 88: Procedure88();break;
	case 89: Procedure89();break;
	case 90: Procedure90();break;
	case 91: Procedure91();break;
	case 92: Procedure92();break;
	case 93: Procedure93();break;
	case 94: Procedure94();break;
	case 95: Procedure95();break;
	case 96: Procedure96();break;
	case 97: Procedure97();break;
	case 98: Procedure98();break;
	case 99: Procedure99();break;
	case 100: Procedure100();break;
	case 101: Procedure101();break;
	case 102: Procedure102();break;
	case 103: Procedure103();break;
	case 104: Procedure104();break;
	default:
		throw exception("Can not get Procedure num!");
		break;
	}
}
void Parser_LL1::Match(VNandVT::VT vt) throw (exception)
{
	stringstream ss;
	m_tokenList.ReadToken(m_token);
	if (vt != m_token.m_lexType)
		throw exception("error");
	switch (vt)
	{
	case Token::ID:
		//for ProgramName->ID #3
		switch (m_VNStack.top())
		{
		case VNandVT::TypeId:
		case VNandVT::ProgramName:
		case VNandVT::IdList:
		case VNandVT::VarIdList:
		case VNandVT::ProcName:
		case VNandVT::FormList:

		case VNandVT::Invar:
			ap.top().tn->m_IDList.insert(ap.top().tn->m_IDList.end(), m_token.m_sem);
			break;
		case VNandVT::Stm:
		case VNandVT::Variable:
			ap.top().tn->m_IDList.insert(ap.top().tn->m_IDList.end(), m_token.m_sem);
			ap.top().tn->m_expType = TreeNode::ExpType::VariK;
			break;
		case VNandVT::TypeDef:
			ap.top().tn->m_IdKName = m_token.m_sem;
			ap.top().tn->m_decType = TreeNode::IdK;
			break;
		case VNandVT::FieldVar:
			ap.top().tn->m_IDList.insert(ap.top().tn->m_IDList.end(), m_token.m_sem);
			ap.top().tn->m_expType = TreeNode::ExpType::VariK;
		default:
			break;
		}
		break;
	case Token::INTEGER:
		if (ap.top().tn->m_decType == TreeNode::ArrayK)
		{
			ap.top().tn->m_decArrayType = TreeNode::IntegerK;
		}
		else ap.top().tn->m_decType = TreeNode::IntegerK;
		break;
	case Token::CHAR:
		if (ap.top().tn->m_decType == TreeNode::ArrayK)
		{
			ap.top().tn->m_decArrayType = TreeNode::CharK;
		}
		else ap.top().tn->m_decType = TreeNode::CharK;
		break;
	case Token::ARRAY:
		ap.top().tn->m_decType = TreeNode::ArrayK;
		break;
	case Token::RECORD:
		ap.top().tn->m_decType = TreeNode::RecordK;
		break;
	case Token::INTC:
		ss << m_token.m_sem;
		switch (m_VNStack.top())
		{
		case VNandVT::Low:
			ss >> ap.top().tn->m_arrayLow;
			break;
		case VNandVT::Top:
			ss >> ap.top().tn->m_arrayTop;
			break;
		case VNandVT::Factor:
			ss >> ap.top().tn->m_expConst;
			ap.top().tn->m_expType = TreeNode::ConstK;
		default:
			break;
		}
		break;
	case Token::VAR:
		if (m_VNStack.top() == VNandVT::Param)
		{
			ap.top().tn->m_paramType = TreeNode::Var;
		}
		break;
	case Token::ASSIGN:
		ap.top().tn->m_stmtType = TreeNode::StmtType::AssignK;
		break;
	case Token::PLUS:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::PLUS;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::SUB:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::MINUS;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::MUL:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::TIMES;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::DIV:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::OVER;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::LT:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::LT;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::EQ:
		ap.top().tn->m_expOpType = TreeNode::ExpOpType::EQ;
		ap.top().tn->m_expType = TreeNode::OpK;
		break;
	case Token::RETURN:
		ap.top().tn->m_stmtType = TreeNode::StmtType::ReturnK;
		break;
	case Token::IF:
		ap.top().tn->m_stmtType = TreeNode::StmtType::IfK;
		break;
	case Token::READ:
		ap.top().tn->m_stmtType = TreeNode::StmtType::ReadK;
		break;
	case Token::WHILE:
		ap.top().tn->m_stmtType = TreeNode::StmtType::WhileK;
		break;
	case Token::WRITE:
		ap.top().tn->m_stmtType = TreeNode::StmtType::WriteK;
		break;
	default://EQ
		break;
	}
	ap.pop();
	m_VNStack.pop();
	
}


void Parser_LL1::Procedure1()
{
	if (!ap.empty())
	{
		
		ap.pop();
		root = new TreeNode(TreeNode::ProK);
		ap.push(VNandVT(VNandVT::ProgramBody, root));//VN
		ap.push(VNandVT(VNandVT::DeclarePart, root));//VN
		ap.push(VNandVT(VNandVT::ProgramHead, root));//VN
	}
	else
		throw exception("error");
}

void Parser_LL1::Procedure2()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		child = ap.top().tn->CreateChild(TreeNode::PHeadK);
		
		ap.pop();
		ap.push(VNandVT(VNandVT::ProgramName, child));
		ap.push(VNandVT(VNandVT::VT::PROGRAM, child));
	}
}
void Parser_LL1::Procedure3()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure4()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ProcDecpart, parent));
		ap.push(VNandVT(VNandVT::VarDecpart, parent));
		ap.push(VNandVT(VNandVT::TypeDecpart, parent));
	}
}
void Parser_LL1::Procedure5()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure6()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::TypeDec, parent));
	}
}
void Parser_LL1::Procedure7()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		child = ap.top().tn->CreateChild(TreeNode::TypeK);
		ap.pop();
		ap.push(VNandVT(VNandVT::TypeDecList, child));
		ap.push(VNandVT(VNandVT::VT::TYPE, child));
	}
}
void Parser_LL1::Procedure8()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::DecK);
		ap.pop();
		ap.push(VNandVT(VNandVT::TypeDecMore, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI,child));
		ap.push(VNandVT(VNandVT::TypeDef, child));
		ap.push(VNandVT(VNandVT::VT::EQ, child));
		ap.push(VNandVT(VNandVT::TypeId, child));
	}
}
void Parser_LL1::Procedure9()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure10()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::TypeDecList, parent));
	}
}


void Parser_LL1::Procedure11()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure12()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::BaseType, parent));
	}
}
void Parser_LL1::Procedure13()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::StructureType, parent));
	}
}
void Parser_LL1::Procedure14()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure15()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::INTEGER, parent));
	}
}
void Parser_LL1::Procedure16()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::CHAR, parent));
	}
}
void Parser_LL1::Procedure17()
{
	if (!ap.empty())
	{
		
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ArrayType, parent));
	}
}
void Parser_LL1::Procedure18()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;

		ap.pop();
		ap.push(VNandVT(VNandVT::RecType, parent));
	}
}
void Parser_LL1::Procedure19()
{
	if (!ap.empty())
	{

		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::BaseType, parent));
		ap.push(VNandVT(VNandVT::VT::OF, parent));
		ap.push(VNandVT(VNandVT::VT::RM, parent));
		ap.push(VNandVT(VNandVT::Top, parent));
		ap.push(VNandVT(VNandVT::VT::DOT, parent));
		ap.push(VNandVT(VNandVT::VT::DOT, parent));
		ap.push(VNandVT(VNandVT::Low, parent));
		ap.push(VNandVT(VNandVT::VT::LM, parent));
		ap.push(VNandVT(VNandVT::VT::ARRAY, parent));
		
		
	}
}

void Parser_LL1::Procedure20()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::INTC, parent));
		
		
	}
}


void Parser_LL1::Procedure21()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::INTC, parent));
		
		
	}
}

void Parser_LL1::Procedure22()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::END, parent));
		ap.push(VNandVT(VNandVT::FieldDecList, parent));
		ap.push(VNandVT(VNandVT::VT::RECORD, parent));
		  
		
	}
}

void Parser_LL1::Procedure23()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::DecK);
		ap.pop();
		ap.push(VNandVT(VNandVT::FieldDecMore, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, child));
		ap.push(VNandVT(VNandVT::IdList, child));
		ap.push(VNandVT(VNandVT::BaseType, child));
		 
		
	}
}

void Parser_LL1::Procedure24()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = parent->CreateChild(TreeNode::DecK);
		ap.pop();
		ap.push(VNandVT(VNandVT::FieldDecMore, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, child));
		ap.push(VNandVT(VNandVT::IdList, child));
		ap.push(VNandVT(VNandVT::ArrayType, child));
		 
		
	}
}

void Parser_LL1::Procedure25()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}

void Parser_LL1::Procedure26()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::FieldDecList, parent));
	}
}

void Parser_LL1::Procedure27()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::IdMore, parent));
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}

void Parser_LL1::Procedure28()
{
	if (!ap.empty())
	{
		ap.pop();
		
		
	}
}

void Parser_LL1::Procedure29()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::IdList, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, parent));
		
		
	}
}

void Parser_LL1::Procedure30()
{
	if (!ap.empty())
	{
		ap.pop();
		
		
	}
}

void Parser_LL1::Procedure31()
{
	if (!ap.empty())
	{
		
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VarDec, parent));
		
		
	}
}

void Parser_LL1::Procedure32()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		child = ap.top().tn->CreateChild(TreeNode::VarK);
		ap.pop();
		ap.push(VNandVT(VNandVT::VarDecList, child));
		ap.push(VNandVT(VNandVT::VT::VAR, child));
		
		
	}
}

void Parser_LL1::Procedure33()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		m_VNStack.push(ap.top().vn);
		child = ap.top().tn->CreateChild(TreeNode::DecK);
		ap.pop();
		ap.push(VNandVT(VNandVT::VarDecMore, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, child));
		ap.push(VNandVT(VNandVT::VarIdList, child));
		ap.push(VNandVT(VNandVT::TypeDef, child));
		 
		
	}
}
void Parser_LL1::Procedure34()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure35()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VarDecList, parent));
	}
}
void Parser_LL1::Procedure36()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VarIdMore, parent));
		ap.push(VNandVT(VNandVT::VT::ID, parent));
		
		
	}
}
void Parser_LL1::Procedure37()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure38()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VarIdList, parent));
		ap.push(VNandVT(VNandVT::VT::COMMA, parent));
	}
}
void Parser_LL1::Procedure39()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}

void Parser_LL1::Procedure40()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ProcDec, parent));
	}
}
void Parser_LL1::Procedure41()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::ProcK);
		ap.pop();
		ap.push(VNandVT(VNandVT::ProcDecMore, parent));
		ap.push(VNandVT(VNandVT::ProcBody, child));
		ap.push(VNandVT(VNandVT::ProcDecPart, child));
		ap.push(VNandVT(VNandVT::VT::SEMI, child));
		ap.push(VNandVT(VNandVT::VT::RS, child));
		ap.push(VNandVT(VNandVT::ParamList, child));
		ap.push(VNandVT(VNandVT::VT::LS, child));
		ap.push(VNandVT(VNandVT::ProcName, child));
		ap.push(VNandVT(VNandVT::VT::PROCEDURE, child));
	}
}
void Parser_LL1::Procedure42()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure43()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ProcDec, parent));
	}
}
void Parser_LL1::Procedure44()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure45()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure46()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ParamDecList, parent));
	}
}
void Parser_LL1::Procedure47()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::DecK);
		ap.pop();
		ap.push(VNandVT(VNandVT::ParamMore, parent));
		ap.push(VNandVT(VNandVT::Param, child));
	}
}
void Parser_LL1::Procedure48()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure49()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ParamDecList, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, parent));
	}
}
void Parser_LL1::Procedure50()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::FormList, parent));
		ap.push(VNandVT(VNandVT::TypeDef, parent));
	}
}
void Parser_LL1::Procedure51()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		m_VNStack.push(ap.top().vn);
		ap.pop();
		ap.push(VNandVT(VNandVT::FormList, parent));
		ap.push(VNandVT(VNandVT::TypeDef, parent));
		ap.push(VNandVT(VNandVT::VT::VAR, parent));
	}
}
void Parser_LL1::Procedure52()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::FidMore, parent));
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure53()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure54()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::FormList, parent));
		ap.push(VNandVT(VNandVT::VT::COMMA, parent));
	}
}
void Parser_LL1::Procedure55()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::DeclarePart, parent));

	}
}
void Parser_LL1::Procedure56()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ProgramBody, parent));
	}
}
void Parser_LL1::Procedure57()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		child = ap.top().tn->CreateChild(TreeNode::StmLK);
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::END, child));
		ap.push(VNandVT(VNandVT::StmList, child));
		ap.push(VNandVT(VNandVT::VT::BEGIN, child));
	}
}
void Parser_LL1::Procedure58()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::StmtK);
		ap.pop();
		ap.push(VNandVT(VNandVT::StmMore, parent));
		ap.push(VNandVT(VNandVT::Stm, child));
	}
}
void Parser_LL1::Procedure59()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure60()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::StmList, parent));
		ap.push(VNandVT(VNandVT::VT::SEMI, parent));
	}
}
void Parser_LL1::Procedure61()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ConditionalStm, parent));
	}
}
void Parser_LL1::Procedure62()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::LoopStm, parent));
	}
}
void Parser_LL1::Procedure63()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::InputStm, parent));
	}
}
void Parser_LL1::Procedure64()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::OutputStm, parent));
	}
}
void Parser_LL1::Procedure65()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ReturnStm, parent));
	}
}
void Parser_LL1::Procedure66()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = parent->CreateChild(TreeNode::ExpK);
		ap.pop();
		ap.push(VNandVT(VNandVT::AssCall, child));
		ap.push(VNandVT(VNandVT::VT::ID, child));
	}
}
void Parser_LL1::Procedure67()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::AssignmentRest, parent));
	}
}
void Parser_LL1::Procedure68()
{
	if (!ap.empty())
	{
		parent = ap.top().tn->GetParent();
		parent->m_stmtType = TreeNode::StmtType::CallK;
		ap.pop();
		ap.push(VNandVT(VNandVT::CallStmRest, parent));
	}
}
void Parser_LL1::Procedure69()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::Exp, parent->GetParent()));
		ap.push(VNandVT(VNandVT::VT::ASSIGN, parent->GetParent()));
		ap.push(VNandVT(VNandVT::VariMore, parent));
	}
}
void Parser_LL1::Procedure70()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::FI, parent));
		ap.push(VNandVT(VNandVT::StmList, parent));
		ap.push(VNandVT(VNandVT::VT::ELSE, parent));
		ap.push(VNandVT(VNandVT::StmList, parent));
		ap.push(VNandVT(VNandVT::VT::THEN, parent));
		ap.push(VNandVT(VNandVT::RelExp, parent));
		ap.push(VNandVT(VNandVT::VT::IF, parent));
	}
}
void Parser_LL1::Procedure71()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ENDWH, parent));
		ap.push(VNandVT(VNandVT::StmList, parent));
		ap.push(VNandVT(VNandVT::VT::DO, parent));
		ap.push(VNandVT(VNandVT::RelExp, parent));
		ap.push(VNandVT(VNandVT::VT::WHILE, parent));
	}
}
void Parser_LL1::Procedure72()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RS, parent));
		ap.push(VNandVT(VNandVT::Invar, parent));
		ap.push(VNandVT(VNandVT::VT::LS, parent));
		ap.push(VNandVT(VNandVT::VT::READ, parent));
	}
}
void Parser_LL1::Procedure73()
{
	if (!ap.empty())
	{
		child = ap.top().tn->CreateChild(TreeNode::ExpK);
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::ID, child));
	}
}
void Parser_LL1::Procedure74()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RS, parent));
		ap.push(VNandVT(VNandVT::Exp, parent));
		ap.push(VNandVT(VNandVT::VT::LS, parent));
		ap.push(VNandVT(VNandVT::VT::WRITE, parent));
	}
}
void Parser_LL1::Procedure75()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RETURN, parent));
	}
}
void Parser_LL1::Procedure76()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RS, parent));
		ap.push(VNandVT(VNandVT::ActParamList, parent));
		ap.push(VNandVT(VNandVT::VT::LS, parent));
	}
}
void Parser_LL1::Procedure77()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure78()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ActParamMore, parent));
		ap.push(VNandVT(VNandVT::Exp, parent));
	}
}
void Parser_LL1::Procedure79()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure80()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::ActParamList, parent));
	}
}
void Parser_LL1::Procedure81()
{
	if (!ap.empty())
	{
		child = ap.top().tn->CreateChild(TreeNode::ExpK);
		ap.pop();
		ap.push(VNandVT(VNandVT::OtherRelE, child));
		ap.push(VNandVT(VNandVT::Exp, child));
	}
}
void Parser_LL1::Procedure82()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::Exp, parent));
		ap.push(VNandVT(VNandVT::CmpOp, parent));
	}
}
void Parser_LL1::Procedure83()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		child = parent->CreateChild(TreeNode::ExpK);
		ap.pop();
		ap.push(VNandVT(VNandVT::OtherTerm, child));
		ap.push(VNandVT(VNandVT::Term, child));
	}
}
void Parser_LL1::Procedure84()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure85()
{
	if (!ap.empty())
	{
		parent = ap.top().tn->GetParent();
		child = parent->CreateChild(TreeNode::ExpK);
		ap.top().tn->ReParent(child);
		ap.pop();
		ap.push(VNandVT(VNandVT::Exp, child));
		ap.push(VNandVT(VNandVT::AddOp, child));
	}
}
void Parser_LL1::Procedure86()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::OtherFactor, parent));
		ap.push(VNandVT(VNandVT::Factor, parent));
	}
}
void Parser_LL1::Procedure87()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure88()
{
	if (!ap.empty())
	{
		parent = ap.top().tn->GetParent();
		child = parent->CreateChild(TreeNode::ExpK);
		ap.top().tn->ReParent(child);
		ap.pop();
		ap.push(VNandVT(VNandVT::Term, child));
		ap.push(VNandVT(VNandVT::MultOp, child));
	}
}
void Parser_LL1::Procedure89()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RS, parent));
		ap.push(VNandVT(VNandVT::Exp, parent));
		ap.push(VNandVT(VNandVT::VT::LS, parent));
	}
}
void Parser_LL1::Procedure90()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::INTC, parent));
	}
}
void Parser_LL1::Procedure91()
{
	if (!ap.empty())
	{
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::Variable, parent));
	}
}
void Parser_LL1::Procedure92()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VariMore, parent));
		ap.push(VNandVT(VNandVT::VT::ID, parent));
	}
}
void Parser_LL1::Procedure93()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure94()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		parent->m_expVarType = TreeNode::ExpVarType::ArrayMember;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RM, parent));
		ap.push(VNandVT(VNandVT::Exp, parent));
		ap.push(VNandVT(VNandVT::VT::LM, parent));
	}
}
void Parser_LL1::Procedure95()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		parent->m_expVarType = TreeNode::ExpVarType::FieldMember;
		ap.pop();
		ap.push(VNandVT(VNandVT::FieldVar, parent));
		ap.push(VNandVT(VNandVT::VT::DOT, parent));
	}
}
void Parser_LL1::Procedure96()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		child = ap.top().tn->CreateChild(TreeNode::ExpK);
		ap.pop();
		ap.push(VNandVT(VNandVT::FieldVarMore, parent));
		ap.push(VNandVT(VNandVT::VT::ID, child));
	}
}
void Parser_LL1::Procedure97()
{
	if (!ap.empty())
	{
		ap.pop();
	}
}
void Parser_LL1::Procedure98()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		parent->m_expVarType = TreeNode::ExpVarType::ArrayMember;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::RM, parent));
		ap.push(VNandVT(VNandVT::Exp, parent));
		ap.push(VNandVT(VNandVT::VT::LM, parent));
	}
}
void Parser_LL1::Procedure99()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::LT, parent));
	}
}
void Parser_LL1::Procedure100()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::EQ, parent));
	}
}
void Parser_LL1::Procedure101()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::PLUS, parent));
	}
}
void Parser_LL1::Procedure102()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::SUB, parent));
		
		
	}
}
void Parser_LL1::Procedure103()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::MUL, parent));
		
		
	}
}
void Parser_LL1::Procedure104()
{
	if (!ap.empty())
	{
		m_VNStack.push(ap.top().vn);
		parent = ap.top().tn;
		ap.pop();
		ap.push(VNandVT(VNandVT::VT::DIV, parent));
		
	}
}



void Parser_LL1::Out()
{
	OutTree(0, root);
}
