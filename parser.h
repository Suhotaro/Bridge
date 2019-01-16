#pragma once

#include <string>

#include "bridges.h"

namespace Parsing
{

class Parser
{
	using Tokens = std::vector<std::string>;
public:
	virtual ~Parser() = default;

	virtual bool Init() = 0;
	virtual bool Parse() = 0;

	Net::Bridges Result() { return bridges; }

protected:
	Net::Bridges bridges;

private:
	Tokens tokens;
};

}
