#pragma once

#include <vector>

namespace Algorithm
{

class Graph;

class DisjointSets final
{
public:
	DisjointSets(const Graph&);

	DisjointSets(const DisjointSets&) = delete;
	DisjointSets& operator=(const DisjointSets&) = delete;

	DisjointSets(DisjointSets&&) = delete;
	DisjointSets& operator=(DisjointSets&&) = delete;

	/*
	Make the parent of the nodes in the path from
	node --> parent[node] point to parent[node]
	*/
	int Find(int node);

	/* Union by rank */
	void Merge(int x, int y);

private:
	std::vector<int> parent;
	std::vector<int> rank;
	int size = -1;
	const int offset = 2;
};

}