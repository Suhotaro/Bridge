#include "stdafx.h"

#include "topology.h"
#include "spanning_tree.h"

namespace Net
{

//TODO: dependency inject based initialization
Topology::Topology()
: graph(std::make_unique<Algorithm::Graph>())
, strategy(std::make_unique<Algorithm::SpanningTreeKruskal>())
{}

void Topology::Add(const Bridge& _bridge)
{
	_bridge.AddTo(*graph.get());
	minPath = strategy->Calculate(*graph.get());
}

void Topology::Remove(const Bridge& _bridge)
{

}

}