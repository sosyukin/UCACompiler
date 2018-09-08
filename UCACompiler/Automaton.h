#pragma once 
struct State
{
	enum TerminalState
	{
		Null,
		ID,
		Integer,
		Border,
		Assign,
		Comment,
		Array,
		Char,
		Eof,
		Other
	};
	State(const int i, const bool be, const TerminalState ter) :id(i), begin(be), terminal(ter){}
	State(){}
	int id;
	bool begin;
	TerminalState terminal;
};
struct Map
{
	int head;//finish
	int tail;//start
	char letter;
};

struct Node
{
	Node(const int h, const char c) :head(h), letter(c){}
	int head;
	char letter;
	//bool operator>(const Node & t){ return (head > t.head); }
	bool operator<(const Node & t){ return (head < t.head); }
};
struct StateNode{
	StateNode(const std::list<Node> & list, const State & st) :edgelist(list), state(st){}
	StateNode(){};
	std::list < Node > edgelist;
	State state;
};
class Automaton
{

public:
	Automaton(std::list<State> & statelist, std::list<Map> & maplist);
	Automaton();
	~Automaton();
	
	void Start();
	bool Get(const char ctrl);
	State::TerminalState End();
	
	Automaton & operator=(const Automaton & automaton);
	Automaton & operator+=(const int n);

	bool Add(Automaton automaton);
	bool Or(Automaton automaton);
	bool Closure();

	void Output();
private:
	State currentstate;
	std::vector<StateNode> map;
	std::vector<StateNode>::iterator laststate;
};

