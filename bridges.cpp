#include "stdafx.h"

#include <algorithm>

#include "bridges.h"

namespace Net
{

bool Bridges::Parse(std::ifstream& fileStream)
{
	std::shared_ptr<Bridge> brdige = std::make_shared<Bridge>();
	if (brdige->Parse(fileStream))
	{
		push_back(brdige);
		return true;
	}
	return false;
}
bool Bridges::Parse()
{
	std::shared_ptr<Bridge> brdige = std::make_shared<Bridge>();
	if (brdige->Parse())
	{
		push_back(brdige);
		return true;
	}
	return false;
}

void Bridges::Dump() const
{
	std::for_each(begin(), end(), [](const std::shared_ptr<Bridge>& item)
									{
										item->Dump();
									});
}

}