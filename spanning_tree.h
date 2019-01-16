#pragma once

#include "graph.h"

namespace Algorithm
{

class SpanningTree
{
public:
	virtual int Calculate(Graph) = 0;
};

class SpanningTreeKruskal: public SpanningTree
{
public:
	virtual int Calculate(Graph) override;
};

}