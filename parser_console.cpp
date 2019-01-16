#include "stdafx.h"

#include "parser_console.h"
#include "bridge.h"

namespace Parsing
{

bool ParserConsole::Parse()
{
	if (!ConsoleOptionParser::Parse())
		return false;

	if (bridges.empty())
	{
		printf("ERROR: no bridges specified\n");
		return false;
	}
	return true;
}

bool ParserConsole::ParseOption(int option)
{
	switch (option)
	{
	case BRIDGE_ADD:			return bridges.Parse();
	case CALCULATE:				//no break;
	default:
		printf("ERROR: never get here\n");
		return false;
	}
}

bool ParserConsole::IsParseStop(int option)
{
	return option == CALCULATE;
}

bool ParserConsole::IsValid(int option)
{
	return option == BRIDGE_ADD || option == CALCULATE;
}

void ParserConsole::Help()
{
	printf("**************************\n");
	printf("help\n");
	printf(" 1 - add new bridge\n");
	printf(" 2 - calculate topoligy\n");
	printf("**************************\n\n");
}



}