#pragma once
class Lexer
{
public:
	Lexer(FileOpModule & fileOpModule);
	~Lexer();
	TokenList GetTokenList();
private:
	Identifier identifier;
	TokenList tokenList;
	int lineNumber;
	Buffer buffer;
	Token token_temp;
public:
	void Out();
};

