#include "stdafx.h"

#include "spanning_tree.h"

#include "graph.h"
#include "disjoint_set.h"

#include <algorithm>

namespace Algorithm
{

int SpanningTreeKruskal::Calculate(Graph _graph)
{
	_graph.Sort();

	// Create disjoint sets
	DisjointSets ds(_graph);

	int minPath = 0;

	// Iterate through all sorted edges
	std::vector<Graph::Data>::const_iterator it;
	for (it = _graph.Edges().begin(); it != _graph.Edges().end(); it++)
	{
		int from = it->second.first;
		int to = it->second.second;

		int set_from = ds.Find(from);
		int set_to = ds.Find(to);

		/*
		Check if the selected edge is creating
		a cycle or not (Cycle is created if u
		and v belong to same set) 
		*/
		if (set_from != set_to)
		{
			// Update MST weight
			minPath += it->first;

			// Merge two sets
			ds.Merge(set_from, set_to);
		}
	}
	return minPath;
}

}