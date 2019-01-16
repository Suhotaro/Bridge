#pragma once

#include "bridge.h"

#include <vector>
#include <memory>

namespace Net
{

class Bridges : public std::vector<std::shared_ptr<Bridge>>
{
public:
	bool Parse(std::ifstream& fileStream);
	bool Parse();

	void Dump() const;
};

}