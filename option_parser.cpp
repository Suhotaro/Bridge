#include "stdafx.h"

#include "option_parser.h"

#include <iostream>
#include <sstream>

bool ConsoleOptionParser::Parse()
{
	int option = NextOption();
	while (IsValid(option) && !IsParseStop(option))
	{
		if (!ParseOption(option))
			return false;
		option = NextOption();
	}
	return true;
}

int ConsoleOptionParser::NextOption()
{
	Help();
	printf("Option >> ");
	std::getline(std::cin, data);
	printf("\n");

	stream.clear();
	stream.str(data);
	stream >> option;
	return option;
}
