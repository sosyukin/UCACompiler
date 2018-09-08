#include "pch.h"
#include "Automaton.h"


Automaton::Automaton(std::list<State> & statelist, std::list<Map> & maplist)
{
//empty:return bool;size:return int
//iterator:point to the list member;    *iterator:get the concent
//statelist.begin():return iterator      std::list<State>::iterator a = statelist.begin();
//statelist.end();   point to the behind of the last one ;return iterator 
//statelist.insert(statelist.end(),something);         statelist.insert(statelist.begin(),something);
//statelist.insert(iterator,something);
int cout = 0;
for (std::list<State>::iterator a = statelist.begin(); a != statelist.end(); a++)
{
	map.insert(map.end(),StateNode());
	map[cout].state = *a;
	for (std::list<Map>::iterator b = maplist.begin(); b != maplist.end(); b++)
	{
		if (b->tail == map[cout].state.id)
		{
			Node tmp{ b->head, b->letter };
			map[cout].edgelist.insert(map[cout].edgelist.end(), tmp);
		}
	}
	cout++;
}
	laststate = map.end() - 1;
}
	

Automaton::Automaton()
{
	State state{ 0, true, State::TerminalState::Other };
	StateNode statenode;
	statenode.state = state;
	map.insert(map.end(), statenode);
	laststate = map.end() - 1;
}


Automaton::~Automaton()
{
}


void Automaton::Start()
{
	currentstate = map.begin()->state;
}


bool Automaton::Get(const char ctrl)
{
	
	for (std::list<Node>::iterator a = map[currentstate.id].edgelist.begin(); a != map[currentstate.id].edgelist.end(); a++)
	{
		if (a->letter==ctrl)
		{
			currentstate = map[a->head].state;
			return true;
		}
	}
	return false;
}


State::TerminalState Automaton::End()
{
	//if (currentstate.terminal==0)
	//{
	return currentstate.terminal;
	//}
	//else return -1;
}


bool Automaton::Add(Automaton automaton)
{
	map[map.size() - 1].state.terminal = State::TerminalState::Null;
	for (std::list<Node>::iterator i = automaton.map[0].edgelist.begin(); i != automaton.map[0].edgelist.end(); i++)
	{
		i->head += laststate->state.id;
		map[map.size() - 1].edgelist.insert(map[map.size() - 1].edgelist.end(), *i);
	}
	for (std::vector<StateNode>::iterator i = automaton.map.begin()+1; i != automaton.map.end(); i++)
	{
		i->state.id += laststate->state.id;
		for (std::list<Node>::iterator j = i->edgelist.begin(); j != i->edgelist.end(); j++)
		{
			j->head += laststate->state.id;
		}
		map.insert(map.end(), *i);
	}
	laststate = map.end() - 1;
	return true;
}


void Automaton::Output()
{
	for (size_t i = 0; i < map.size(); i++)
	{
		std::cout << "SN[" << i << "] = {" << map[i].state.id << "," << map[i].state.begin << "," << map[i].state.terminal << "}";
		for (std::list<Node>::iterator j = map[i].edgelist.begin(); j != map[i].edgelist.end(); j++)
		{
			std::cout << "-" << j->letter << "->|" << j->head << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "-----" << std::endl;
	
}


Automaton & Automaton::operator=(const Automaton & automaton)
{
	//TODO: insert return statement here
	map = automaton.map;
	laststate = map.end() - 1;
	return *this;
}

bool Automaton::Or(Automaton automaton)
{
	map[0].state.begin = false;
	automaton.map[0].state.begin = false;
	map[map.size() - 1].state.terminal = State::TerminalState::Null;
	automaton.map[map.size() - 1].state.terminal = State::TerminalState::Null;
	*this += 1;
	std::list<Node> tmp;
	tmp.insert(tmp.end(), Node(1, '\0'));
	map.insert(map.begin(), StateNode(tmp, State(0, true, State::TerminalState::Null)));
	int end = map.size() - 1;
	automaton += map.size();
	map[0].edgelist.insert(map[0].edgelist.end(), Node(automaton.map[0].state.id, '\0'));
	for (std::vector<StateNode>::iterator i = automaton.map.begin(); i != automaton.map.end(); i++)
	{
		map.insert(map.end(), *i);
	}
	map[end].edgelist.insert(map[end].edgelist.end(), Node(map.size(), '\0'));
	map[map.size() - 1].edgelist.insert(map[map.size() - 1].edgelist.end(), Node(map.size(), '\0'));
	map.insert(map.end(), StateNode(std::list<Node>(), State(map.size(), false, State::TerminalState::Other)));
	laststate = map.end() - 1;
	return true;
}


Automaton & Automaton::operator+=(const int n)
{
	for (std::vector<StateNode>::iterator i = map.begin(); i != map.end(); i++)
	{
		i->state.id += n;
		for (std::list<Node>::iterator j = i->edgelist.begin(); j != i->edgelist.end(); j++)
		{
			j->head += n;
		}
	}
	return *this;
}


bool Automaton::Closure()
{
	map[0].state.begin = false;
	map[map.size() - 1].state.terminal = State::TerminalState::Null;
	map[map.size() - 1].edgelist.insert(map[map.size() - 1].edgelist.end(), Node(0, '\0'));
	*this += 1;
	Node node(1, '\0');
	map.insert(map.begin(), StateNode(std::list<Node>(&node, &node + 1), State(0, true, State::TerminalState::Null)));
	map.insert(map.end(), StateNode(std::list<Node>(), State(map.size(), false, State::TerminalState::Other)));
	map[map.size() - 2].edgelist.insert(map[map.size() - 2].edgelist.end(), Node(map.size() - 1, '\0'));
	map[0].edgelist.insert(map[0].edgelist.end(), Node(map.size() - 1, '\0'));
	laststate = map.end() - 1;
	return true;
}
