#include "stdafx.h"

#include "disjoint_set.h"
#include "graph.h"

namespace Algorithm
{

DisjointSets::DisjointSets(const Graph& _graph) : size(_graph.MaxEdge())
{
	parent.resize(size + offset);
	rank.resize(size + offset);

	// Initially, all vertices are in different sets and have rank 0.
	for (int i = 0; i <= size; i++)
	{
		rank[i] = 0;
		parent[i] = i; //every element is parent of itself
	}
}

int DisjointSets::Find(int node)
{
	if (node != parent[node])
		parent[node] = Find(parent[node]);
	return parent[node];
}

void DisjointSets::Merge(int x, int y)
{
	x = Find(x);
	y = Find(y);

	/* Make tree with smaller height a subtree of the other tree  */
	if (rank[x] > rank[y])
		parent[y] = x;
	else
		parent[x] = y;

	if (rank[x] == rank[y])
		rank[y]++;
}

}