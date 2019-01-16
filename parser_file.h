#pragma once

#include "parser.h"
#include "file_stream_raii.h"

namespace Parsing
{

class ParserFile : public Parser
{
public:
	ParserFile(int argc, char **argv);

	virtual bool Init() override;
	virtual bool Parse() override;

private:
	std::string fileName;
	std::ifstream fileStream;
	FileStreamRAII fileStreamRAII;

	std::string data;
	std::istringstream stream;
};

}