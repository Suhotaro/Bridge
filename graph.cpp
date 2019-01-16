#include "stdafx.h"

#include "graph.h"

#include <algorithm>
#include <functional>

namespace Algorithm
{

void Graph::AddEdge(int _from, int _to, int _weight)
{
	if (!HasVertex(_from))
		++numVertices;

	if (!HasVertex(_to))
		++numVertices;

	edges.push_back({ _weight,{ _from, _to }});
	numEdges++;
}

void Graph::Sort()
{
	std::sort(edges.begin(), edges.end(), std::greater<Graph::Data>());
}

int Graph::MaxEdge() const
{
	if (edges.empty())
		return 0;

	int maxEdge = 0;
	std::for_each(edges.begin(),
		edges.end(),
		[&maxEdge](const Data& _item)
		{
			if (maxEdge < _item.second.first)
				maxEdge = _item.second.first;

			if (maxEdge < _item.second.second)
				maxEdge = _item.second.second;
		});
	return maxEdge;
}

bool Graph::HasVertex(int _vertex)
{
	Iterator it = std::find_if(edges.begin(),
		edges.end(),
		[&_vertex](const Data& item)
	{
		return item.second.first == _vertex || item.second.second == _vertex;
	});

	return it != edges.end();
}

}