#include "stdafx.h"
#include "app.h"

#include <algorithm>

#include "parser_factory.h"
#include "parser.h"

namespace App
{

bool Application::Init(int argc, char **argv)
{
	std::shared_ptr<Parsing::Parser> parser = Parsing::ParserFactory::Factory(argc, argv);
	if (!parser->Init())
	{
		printf("FAIL: parser init\n");
		return false;
	}

	if (!parser->Parse())
	{
		printf("FAIL: parser parse\n");
		return false;
	}

	bridges = parser->Result();
	return !bridges.empty();
}

void Application::Start()
{
	std::for_each(bridges.begin(),
				  bridges.end(),
				  [this](std::shared_ptr<Net::Bridge> _bridge)
				  {
						mediator->BridgeAdd(_bridge);
				  });

	bridges.Dump();
}

int Application::Result() const
{
	return bridges.at(0)->MinPath();
}

}