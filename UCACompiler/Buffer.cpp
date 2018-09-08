#include "pch.h"
#include "Buffer.h"


Buffer::Buffer()
{
	
}


Buffer::~Buffer()
{
}

void Buffer::Add(char t)
{
	buffer.insert(buffer.end(),t);
	return;
}

std::string Buffer::Get()
{
	return buffer;
}

void Buffer::Back()
{
	buffer.erase(buffer.end() - 1);
	return;
}

void Buffer::Clear()
{
	buffer.clear();
}
