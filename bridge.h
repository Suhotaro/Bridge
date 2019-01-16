#pragma once

namespace Net { class Topology; }

#include "ports.h"
#include "option_parser.h"
#include "topology.h"

namespace Algorithm { class Graph; };

namespace Net
{

class Bridge final : public ConsoleOptionParser
{
	enum Opeartion
	{
		PORT_ADD = 1,
		BACK,
	};

public:
	Bridge();

	void OnReceivedBPDU(const Bridge&);
	void AddTo(Algorithm::Graph&) const;

	int Id() const { return id; }
	int MinPath() const;

	bool Parse(std::ifstream& fileStream);
	bool Parse();

	void Dump() const;

private:
	//Console
	virtual void Help() override final;
	virtual bool IsValid(int option) override final;
	virtual bool IsParseStop(int option) override final;
	virtual bool ParseOption(int option) override final;

	void BridgeIdConsoleGet();

	//Util
	template <typename T, typename STREAM>
	void ReadMemberFile(T& res, STREAM& _stream)
	{
		std::getline(_stream, data);
		stream.clear();
		stream.str(data);

		std::string trash;
		stream >> trash >> trash;
		stream >> res;
	}

	template <typename T, typename STREAM>
	void ReadMemberConsole(T& res, STREAM& _stream)
	{
		std::getline(_stream, data);
		stream.clear();
		stream.str(data);
	}

	std::string data;
	std::stringstream stream;

	int id = -1;
	bool isRoot = true;

	Ports ports;
	std::unique_ptr<Topology> topology;
};

}