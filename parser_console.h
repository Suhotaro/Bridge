#pragma once

#include "parser.h"
#include "option_parser.h"

namespace Parsing
{

class ParserConsole : public Parser, public ConsoleOptionParser
{
	enum Opeartion
	{
		BRIDGE_ADD = 1,
		CALCULATE,
	};

public:
	virtual bool Init() override { return true; }
	virtual bool Parse() override;

private:
	virtual	void Help() override final;
	virtual bool IsValid(int option) override final;
	virtual bool IsParseStop(int option) override final;
	virtual bool ParseOption(int option) override final;

	int option = -1;
};

}