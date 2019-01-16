#include "stdafx.h"

#include "mediator.h"

#include <algorithm>

namespace Net
{

void Mediator::BridgeAdd(std::shared_ptr<Bridge> bridge)
{
	network.push_back(bridge);

	//TODO: It would be cool to implement it as sendig and receiving of 
	std::for_each(network.begin(), network.end(), [bridge](std::shared_ptr<Bridge> _bridge)
	{
		if (_bridge->Id() == bridge->Id())
			return;

		_bridge->OnReceivedBPDU(*bridge.get());
		bridge->OnReceivedBPDU(*_bridge.get());
	});
}

}