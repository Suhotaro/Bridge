#include "stdafx.h"

#include "parser_factory.h"
#include "parser_console.h"
#include "parser_file.h"

namespace Parsing
{

std::shared_ptr<Parser> ParserFactory::Factory(int argc, char **argv)
{
	if (argc == 1)
		return std::make_shared<ParserConsole>();
	else
		return std::make_shared<ParserFile>(argc, argv);
}

}