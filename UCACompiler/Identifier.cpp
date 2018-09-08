#include "pch.h"
#include "Identifier.h"


Identifier::Identifier()
{
}


Identifier::~Identifier()
{
}

char Identifier::Check(const char c){
	/*c是大写字母或小写字母，返回‘L’
		c是数字，返回’D’
		c是 + , -, *, / , (, ), ; , [, ], = , <, EOF, 空白，返回’S’
	
		 */
	if ((c >= '0') && (c <= '9'))
	{
		return 'D';
	}
	else if (((c >= 'a') && (c <= 'z')) || ((c >= 'A')&&(c<='Z')))
	{
		return 'L';
	}
	else 
	{
		switch (c)
		{
		case EOF:return 'E';
		default:
			return c;
		}
	}
}