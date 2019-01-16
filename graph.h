#pragma once

#include <vector>

namespace Algorithm
{

class Graph
{
public:
	using Edge = std::pair<int, int>;
	using Data = std::pair<int, Edge>;
	using EdgesWithWeight = std::vector<Data>;
	using Iterator = std::vector<std::pair<int, Graph::Edge>>::iterator;

	void AddEdge(int from, int to, int weight);
	int MaxEdge() const;
	void Sort();

	const EdgesWithWeight& Edges() const { return edges; };

private:
	bool HasVertex(int vertex);

	EdgesWithWeight edges;
	int numVertices = 0;
	int numEdges = 0;
};

}