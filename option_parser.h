#pragma once

#include <sstream>

class ConsoleOptionParser
{
public:
	bool Parse();

	int NextOption();

	virtual void Help() = 0;
	virtual bool IsValid(int option) = 0;
	virtual bool IsParseStop(int option) = 0;
	virtual bool ParseOption(int option) = 0;

private:
	int option = -1;

	std::string data;
	std::stringstream stream;
};