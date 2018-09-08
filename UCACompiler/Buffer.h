#pragma once
class Buffer
{
public:
	Buffer();
	~Buffer();
	void Add(char c);
	std::string Get();
	void Back();
	
private:
	std::string buffer;
public:
	void Clear();
};

