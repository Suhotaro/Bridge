#pragma once

#include <memory>
#include <vector>
#include <string>

#include "parser.h"

namespace Parsing
{

class ParserFactory
{
public:
	static std::shared_ptr<Parser> Factory(int argc, char **argv);
};

}