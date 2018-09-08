#pragma once
class TokenList
{
public:
	TokenList();
	~TokenList();
	void Add(const Token & token);
	void Out();
	bool ReadToken(Token & token) throw(exception);
	Token GetToken();
	void operator=(TokenList tokenList);
private:
	std::list<Token> tokenlist;
	std::list<Token>::iterator m_current;
public:
	bool Empty();
};