#include "stdafx.h"

#include "parser_file.h"

#include <sstream>

namespace Parsing
{

ParserFile::ParserFile(int argc, char **argv)
: fileName(argv[2])
, fileStreamRAII(fileStream)
{}

bool ParserFile::Init()
{
	fileStream.open(fileName, std::ifstream::in);
	if (fileStream.fail())
	{
		printf("FAIL: open file \"%s\"", fileName.c_str());
		return false;
	}
	return true;
}

bool ParserFile::Parse()
{
	bool ret = false;

	while (!fileStream.eof())
	{
		std::getline(fileStream, data);
		if (data.find("BRIDGE") != std::string::npos)
		{
			ret = bridges.Parse(fileStream);
			if (!ret)
				return false;
		}
	}
	return true;
}

}