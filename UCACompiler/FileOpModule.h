#pragma once
class FileOpModule
{
public:
	FileOpModule(const std::string & filename);
	~FileOpModule();
	char Get();
private:
	std::ifstream fin;
	std::list<std::string> strlist;
	std::list<std::string>::iterator currentstr;
	int m_lineNumber;
	char m_buffer;
	bool m_back;
public:
	void Back();
	int GetLineNum();
	bool eof();
};

