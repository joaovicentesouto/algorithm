#include "graph_algorithms.h"

using namespace lemon;
using namespace std;

namespace routing {

GraphAlgorithms::GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<int>& cost, size_t n, size_t m) :
	mGraph(graph),
	mCost(cost),
	mAmountNodes(n),
	mAmountEdges(m)
{
	cout << "Criado!" << endl;
};

GraphAlgorithms::~GraphAlgorithms()
{
	cout << "Destruido!" << endl;
};

vector<size_t>* GraphAlgorithms::dijkstra(ListGraph::Node& source, ListGraph::Node& target)
{
	// Inicializacao
	vector<size_t> pathCost(mAmountNodes);
	vector<size_t> parents(mAmountNodes);
	vector<bool> closed(mAmountNodes);

	fill(pathCost.begin(), pathCost.end(), static_cast<size_t>(-1));
	fill(parents.begin(), parents.end(), static_cast<size_t>(-1));
	fill(closed.begin(), closed.end(), false);

	pathCost[mGraph.id(source)] = 0;
	parents[mGraph.id(source)] = mGraph.id(source);

	size_t minimum, current, newPath, adjacent;
	while (!closed[mGraph.id(target)])
	{
		// Encontra o menor O(n)
		minimum = current = static_cast<size_t>(-1);
		for (auto i = 0; i < mAmountNodes; ++i)
		{
			if (!closed[i] && pathCost[i] < minimum)
			{
				current = i;
				minimum = pathCost[i];
			}
		}

		// Fecha vertice O(1)
		closed[current] = true;

		// Se fechar o target, sai...
		if (closed[mGraph.id(target)])
		{
			break;
		}

		// Atualiza adjacentes O(m/n)
		for (ListGraph::OutArcIt out(mGraph, mGraph.nodeFromId(current)); out != INVALID; ++out)
		{
			adjacent = mGraph.id(mGraph.target(out));
			newPath = pathCost[current] + mCost[out];
			if (!closed[mGraph.id(mGraph.target(out))] && (newPath < pathCost[adjacent]))
			{
				pathCost[adjacent] = newPath;
				parents[adjacent] = current;
			}
		}
	}

	// Achando o caminho
	vector<size_t>* leastCostPath = new vector<size_t>();
	current = mGraph.id(target);
	while (current != mGraph.id(source))
	{
		leastCostPath->push_back(current);
		current = parents[current];
	}
	leastCostPath->push_back(current);

	return leastCostPath;

};

void GraphAlgorithms::test()
{
	for (ListGraph::NodeIt n(mGraph); n != INVALID; ++n)
	{
		for (ListGraph::OutArcIt out(mGraph, n); out != INVALID; ++out)
		{
			cout << mGraph.id(mGraph.source(out)) << " -> "
			<< mGraph.id(mGraph.target(out))
			<< " := " << mCost[out] << endl;
		}
	}
};

}  // namespace routing