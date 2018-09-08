#include "pch.h"
#include "Init.h"

using namespace std;
void InitAutomaton(list<State> & stateList, list<Map> & mapList)
{
	//shixian
	State state[15] = { 
		{ 0, true, State::Null },
		{ 1, false, State::Null },
		{ 2, false, State::ID },
		{ 3, false, State::Null },
		{ 4, false, State::Integer },
		{ 5, false, State::Border },
		{ 6, false, State::Null },
		{ 7, false, State::Assign },
		{ 8, false, State::Comment },
		{ 9, false, State::Null },
		{ 10, false, State::Array },
		{ 11, false, State::Null },
		{ 12, false, State::Null },
		{ 13, false, State::Char },
		{ 14, false, State::Eof }
	};
	
	Map map[] = { { 1, 0, 'L' }, { 1, 1, 'L' }, { 1, 1, 'D' }, { 2, 1, '+' }, { 2, 1, '-' }, { 2, 1, '*' }, { 2, 1, '/' }, { 2, 1, '(' }, { 2, 1, ')' }, { 2, 1, ';' }, { 2, 1, '[' }, { 2, 1, ']' }, { 2, 1, '=' }, { 2, 1, '<' }, { 2, 1, 'E' }, { 2, 1, ' ' }, { 2, 1, ':' }, { 2, 1, '{' }, { 2, 1, '.' }, { 2, 1, '\'' }, { 2, 1, ',' }, { 2, 1, '\t' }, { 2, 1, '\n' },
	{ 3, 0, 'D' }, { 3, 3, 'D' }, { 4, 3, '+' }, { 4, 3, '-' }, { 4, 3, '*' }, { 4, 3, '/' }, { 4, 3, '(' }, { 4, 3, ')' }, { 4, 3, ';' }, { 4, 3, '[' }, { 4, 3, ']' }, { 4, 3, '=' }, { 4, 3, '<' }, { 4, 3, 'E' }, { 4, 3, ' ' }, { 4, 3, ':' }, { 4, 3, '{' }, { 4, 3, '.' }, { 4, 3, '\'' }, { 4, 3, ',' }, { 4, 3, '\t' }, { 4, 3, '\n' },
	{ 5, 0, '+' }, { 5, 0, '-' }, { 5, 0, '*' }, { 5, 0, '/' }, { 5, 0, '(' }, { 5, 0, ')' }, { 5, 0, ';' }, { 5, 0, '[' }, { 5, 0, ']' }, { 5, 0, '=' }, { 5, 0, '<' }, { 5, 0, ',' }, { 5, 0, '.' }, { 5, 0, ' ' }, { 5, 0, '\t' }, { 5, 0, '\n' },
	{ 6, 0, ':' }, {7,6,'='},
	{8,0,'{'},
	{ 14, 0, 'E' },//{ 9, 0, '.' }, { 10, 9, '.' }, { 14, 9, 'E' }, { 14, 9, 'L' }, { 14, 9, 'D' }, { 14, 9, '+' }, { 14, 9, '-' }, { 14, 9, '*' }, { 14, 9, '/' }, { 14, 9, '(' }, { 14, 9, ')' }, { 14, 9, ';' }, { 14, 9, '[' }, { 14, 9, ']' }, { 14, 9, '=' }, { 14, 9, '<' }, { 14, 9, ' ' }, { 14, 9, ':' }, { 14, 9, '{' }, { 14, 9, '.' }, { 14, 9, '\'' }, { 14, 9, ',' }, { 14, 9, '\t' }, { 14, 9, '\n' },
	{ 11, 0, '\'' }, { 12, 11, 'L' }, { 12, 11, 'D' }, { 13, 12, 'Z' } };
	
	stateList.assign(state, state + sizeof(state) / sizeof(State));
	mapList.assign(map, map + sizeof(map) / sizeof(Map));

	
}