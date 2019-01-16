#pragma once

#include <string>
#include <fstream>
#include <sstream>

namespace Net
{

class Port
{
public:
	Port(int _portId = 0) : id(_portId) {}

	enum class ePortState
	{
		NONE,
		DESIGNATED,
		ROOT,
		BLOCKED,
	};

	bool Parse(std::ifstream& fileStream);
	bool Parse();

	int PahtCost() const { return pathCost; }
	int LanIdConnectedTo() const { return lanID; }

	void PortState(ePortState _state) { state = _state; }
	ePortState PortState() const { return state; }

	void Dump() const;
	static std::string ToString(ePortState);

private:
	template <typename T, typename STREAM>
	void ReadMemberFile(T& res, STREAM& _stream, int N)
	{
		std::getline(_stream, data);
		stream.clear();
		stream.str(data);

		std::string trash;
		//XXX: Weired
		for (int i = 0; i < N; i++)
			stream >> trash;
		stream >> res;
	}

	template <typename T, typename STREAM>
	void ReadMemberConsole(T& res, STREAM& _stream)
	{
		std::getline(_stream, data);
		stream.clear();
		stream.str(data);

		stream >> res;
	}

	int id = -1;
	int pathCost = -1;
	std::string LAN = "";
	const int lanOfsset = 10000;
	int lanID = -1;
	ePortState state = ePortState::NONE;

	std::string data;
	std::stringstream stream;
};

}