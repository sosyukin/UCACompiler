#include "pch.h"
#include "FileOpModule.h"
#define MAXLEN 100

FileOpModule::FileOpModule(const std::string & filename)
	: m_lineNumber(0)
	, m_buffer(0)
	, m_back(false)
{
	fin = std::ifstream(filename);
	if (!fin.is_open())
	{
		std::cout << "Can not open this file! Exit." << std::endl;
		exit(0);
	}
}


FileOpModule::~FileOpModule()
{
	fin.close();
}


char FileOpModule::Get()
{
	if (m_back)
	{
		m_back = false;
		return m_buffer;
	}
	else
	{
		if (m_buffer == '\n' || m_buffer == 0)
		{
			m_lineNumber++;
		}
		m_buffer = fin.get();
		return m_buffer;
	}
	
}


void FileOpModule::Back()
{
	m_back = true;
}


int FileOpModule::GetLineNum()
{
	return m_lineNumber;
}


bool FileOpModule::eof()
{
	return fin.eof();
}
