#include "stdafx.h"

#include <algorithm>

#include "ports.h"

namespace Net
{

bool Ports::Parse(int portId, std::ifstream& fileStream)
{
	std::shared_ptr<Port> port = std::make_shared<Port>(portId);
	if (port->Parse(fileStream))
	{
		push_back(port);
		return true;
	}
	return false;
}

bool Ports::Parse()
{
	std::shared_ptr<Port> port = std::make_shared<Port>();
	if (port->Parse())
	{
		push_back(port);
		return true;
	}
	return false;
}

void Ports::Dump() const
{
	std::for_each(begin(), end(), [](const std::shared_ptr<Port>& item)
									{
										item->Dump();
									});
}

}