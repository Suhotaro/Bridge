#include "stdafx.h"
#include "port.h"

#include <iostream>

namespace Net
{

bool Port::Parse(std::ifstream& fileStream)
{
	//TODO: validation of parameters
	ReadMemberFile(pathCost, fileStream, 2);
	ReadMemberFile(LAN, fileStream, 3);

	//HACK: Simplification of calculations.
	//	LANID must not be equival to any bridgeId.
	//	LANID will be used further as vertice in Spanning Tree algorithm.
	lanID = LAN.at(0) + lanOfsset;

	return true;
}

bool Port::Parse()
{
	//TODO: validation of parameters
	printf("Port ID >> ");

	ReadMemberConsole(id, std::cin);

	printf("Path Cost >> ");
	ReadMemberConsole(pathCost, std::cin);

	printf("Connected LAN >> ");
	ReadMemberConsole(LAN, std::cin);

	//HACK: Simplification of calculations.
	//	LANID must not be equival to any bridgeId.
	//	LANID will be used further as vertice in Spanning Tree algorithm.
	lanID = LAN.at(0) + lanOfsset;

	printf("\n");

	return true;
}

void Port::Dump() const
{
	printf("  Port:\n"
			"    id:%d\n"
			"    pathCost:%d\n"
			"    ConnectedTo:%s\n"
			"    State:%s\n"
			, id
			, pathCost
			, LAN.c_str()
			, ToString(state).c_str());
}

std::string Port::ToString(Port::ePortState Port)
{
	switch (Port)
	{
	case Port::ePortState::NONE:		return "NONE";
	case Port::ePortState::DESIGNATED:	return "DESIGNATED";
	case Port::ePortState::ROOT:		return "ROOT";
	case Port::ePortState::BLOCKED:		return "BLOCKED";
	default:							return "";
	}
}

}