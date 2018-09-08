#pragma once
#include "Automaton.h"
#define epsilon '\0'
class RegularExpression :
	public Automaton
{
public:
	RegularExpression();
	~RegularExpression();
	RegularExpression & operator+(RegularExpression & regularexpression);
	RegularExpression & operator*();
	RegularExpression & operator|(RegularExpression & regularexpression);
};

