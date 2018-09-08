#include "pch.h"
#include "TokenList.h"

TokenList::TokenList()
{
	m_current = tokenlist.begin();
}


TokenList::~TokenList()
{
}

void TokenList::Add(const Token & token)
{
	tokenlist.insert(tokenlist.end(), token);
}

//传入Token，将其保存在类中。
void TokenList::Out()
{
	std::list<Token>::iterator pr;
	std::cout << setw(4) << "Num" << setw(10) << "lexType" << setw(10) << "Sem"<< std::endl;
	std::cout << setw(4) << "---" << setw(10) << "-------" << setw(10) << "---" << std::endl;
	for (pr = tokenlist.begin();  pr!= tokenlist.end(); pr++)
	{
		pr->Out();
	}
}


bool TokenList::ReadToken(Token & token) throw(exception)
{
	if (m_current == tokenlist.end())
	{
		throw exception("We don't have other token.");
		return false;
	}
		
	else
	{
		token = *m_current;
		m_current++;
	}
	return true;
}


Token TokenList::GetToken()
{
	return *m_current;
}


void TokenList::operator=(TokenList tokenList)
{
	this->tokenlist = tokenList.tokenlist;
	this->m_current = this->tokenlist.begin();
}

bool TokenList::Empty()
{
	return m_current == this->tokenlist.end();
}
