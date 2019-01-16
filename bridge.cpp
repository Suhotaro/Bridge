#include "stdafx.h"

#include "bridge.h"
#include "graph.h"

#include <iostream>
#include <fstream>
#include <sstream>

namespace Net
{

Bridge::Bridge() : topology(std::make_unique<Topology>())
{}

void Bridge::OnReceivedBPDU(const Bridge& _bridge)
{
	//TODO:	There is possible equivalent case but I do not have
	//		mac addresses to make final decision here
	if (id > _bridge.id)
		isRoot = false;

	topology->Add(_bridge);
}

void Bridge::AddTo(Algorithm::Graph& graph) const
{
	//NOTE: Since graph is not directed there is no need of adding reverse edge
	for (const std::shared_ptr<Port>& port : ports)
		graph.AddEdge(id, port->LanIdConnectedTo(), port->PahtCost());
}

int Bridge::MinPath() const
{
	return topology->MinPath();
}

bool Bridge::Parse(std::ifstream& fileStream)
{
	//TODO: validation of parameters
	ReadMemberFile(id, fileStream);

	while (!fileStream.eof())
	{
		std::streamoff positionBefore = fileStream.tellg();
		std::getline(fileStream, data);
		if (data.empty())
			continue;

		if (data.find("Port") != std::string::npos)
		{
			fileStream.seekg(positionBefore);
			//XXX: Find other way of reading port ID
			int portId = -1;
			ReadMemberFile(portId, fileStream);;
			if (!ports.Parse(portId, fileStream))
				return false;
		}
		else
		{
			fileStream.seekg(positionBefore);
			break;
		}
	}

	topology->Add(*this);

	return true;
}

bool Bridge::Parse()
{
	//TODO: validation of parameters
	BridgeIdConsoleGet();

	bool ret = ConsoleOptionParser::Parse();

	printf("\n");

	topology->Add(*this);

	return ret;
}

void Bridge::BridgeIdConsoleGet()
{
	printf("Bridge ID >> ");
	std::getline(std::cin, data);
	stream.clear();
	stream.str(data);
	stream >> id;
}

bool Bridge::ParseOption(int option)
{
	switch (option)
	{
	case PORT_ADD:	return ports.Parse();
	case BACK:		//no break;
	default:
		printf("ERROR: never get here\n");
		return false;
	}
}

bool Bridge::IsParseStop(int option)
{
	return option == BACK;
}

bool Bridge::IsValid(int option)
{
	return option == PORT_ADD || option == BACK;
}

void Bridge::Help()
{
	printf("**************************\n");
	printf("bridge help\n");
	printf(" 1 - add port\n");
	printf(" 2 - back\n");
	printf("**************************\n\n");
}

void Bridge::Dump() const
{
	printf("---------------------\n");

	printf("Bridge:\n"
			"  id:%d\n", id);

	ports.Dump();

	printf("---------------------\n\n");
}

}