#pragma once

namespace Net { class Bridge; }

#include "bridge.h"
#include "graph.h"

#include <memory>

namespace Algorithm { class SpanningTreeKruskal; }

namespace Net
{

class Topology final
{
public:
	Topology();

	void Add(const Bridge&);
	void Remove(const Bridge&);

	int MinPath() const { return minPath; }

private:
	std::unique_ptr<Algorithm::Graph> graph;
	int minPath = 0;

	std::shared_ptr<Algorithm::SpanningTreeKruskal> strategy;
};

}
