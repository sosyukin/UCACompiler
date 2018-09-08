#include "pch.h"
#include "Identifier.h"


Identifier::Identifier()
{
}


Identifier::~Identifier()
{
}

char Identifier::Check(const char c){
	/*c�Ǵ�д��ĸ��Сд��ĸ�����ء�L��
		c�����֣����ء�D��
		c�� + , -, *, / , (, ), ; , [, ], = , <, EOF, �հף����ء�S��
	
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