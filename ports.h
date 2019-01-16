#pragma once

#include <vector>
#include <memory>

#include "port.h"

namespace Net
{

class Ports : public std::vector<std::shared_ptr<Port>>
{
public:
	bool Parse(int portId, std::ifstream& fileStream);
	bool Parse();

	void Dump() const;
};

}