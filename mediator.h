#pragma once

#include "bridge.h"

namespace Net
{

class Mediator
{
	using Network = std::vector<std::shared_ptr<Bridge>>;
public:
	void BridgeAdd(std::shared_ptr<Bridge>);
private:
	Network network;
};

}