#pragma once

#include <memory>

#include "bridges.h"
#include "mediator.h"

namespace App
{

class Application final
{
public:
	Application() : mediator(std::make_unique<Net::Mediator>()) {}

	bool Init(int argc, char **argv);
	void Start();

	int Result() const;

private:
	Net::Bridges bridges;
	std::unique_ptr<Net::Mediator> mediator;
};

}