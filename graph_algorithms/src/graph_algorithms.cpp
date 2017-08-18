#include "./graph_algorithms.h"

using namespace lemon;
using namespace std;

namespace routing {

GraphAlgorithms::GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<int>& cost, size_t n, size_t m) :
	mGraph(graph),
	mCost(cost),
	mAmountNodes(n),
	mAmountEdges(m)
{
        //cout << "Criado!" << endl;
};

GraphAlgorithms::~GraphAlgorithms()
{
        //cout << "Destruido!" << endl;
};

vector<size_t>* GraphAlgorithms::dijkstra(ListGraph::Node& source, ListGraph::Node& target)
{
	// Inicializacao
        vector<size_t> pathCost(mAmountNodes ,static_cast<size_t>(-1));

        // Tentando
        //ListGraph::NodeMap<size_t> pathCost(mGraph, static_cast<size_t>(-1));

        // Funcionando
        ListGraph::NodeMap<size_t> parents(mGraph, static_cast<size_t>(-1));
        ListGraph::NodeMap<bool> closed(mGraph, false);

	pathCost[mGraph.id(source)] = 0;
        parents[source] = mGraph.id(source);

        size_t minimum, current, newPath;
        while (!closed[target])
	{
		// Encontra o menor O(n)
                minimum = current = static_cast<size_t>(-1);
		for (auto i = 0; i < mAmountNodes; ++i)
		{
                        if (!closed[mGraph.nodeFromId(i)] && pathCost[i] < minimum)
			{
                                current = i;
				minimum = pathCost[i];
			}
		}

		// Fecha vertice O(1)
                closed[mGraph.nodeFromId(current)] = true;

		// Atualiza adjacentes O(m/n)
                for (ListGraph::OutArcIt out(mGraph, mGraph.nodeFromId(current)); out != INVALID && !closed[target]; ++out)
                {
                        newPath = pathCost[current] + mCost[out];
                        if (!closed[mGraph.target(out)] && (newPath < pathCost[mGraph.id(mGraph.target(out))]))
			{
                                pathCost[mGraph.id(mGraph.target(out))] = newPath;
                                parents[mGraph.target(out)] = current;
			}
		}
	}

	// Achando o caminho
        vector<size_t>* leastCostPath = new vector<size_t>();
        current = mGraph.id(target);
        while (current != mGraph.id(source))
	{
                leastCostPath->push_back(current);
                current = parents[mGraph.nodeFromId(current)];
	}
        leastCostPath->push_back(current);

	return leastCostPath;

};

std::vector<std::size_t>* GraphAlgorithms::dijkstra(size_t source, size_t target)
{
	if (source > mAmountNodes || target > mAmountNodes)
	{
		throw std::out_of_range("Index out of range!");
	}

	ListGraph::Node s = mGraph.nodeFromId(source);
	ListGraph::Node t = mGraph.nodeFromId(target);

	return dijkstra(s, t);
}


int GraphAlgorithms::test()
{
	cout << "\nTodos os nodes com seus adjacentes:\n";
	for (ListGraph::NodeIt n(mGraph); n != INVALID; ++n)
	{
		for (ListGraph::OutArcIt out(mGraph, n); out != INVALID; ++out)
		{
			cout << mGraph.id(mGraph.source(out)) << " -> "
			<< mGraph.id(mGraph.target(out))
			<< " := " << mCost[out] << endl;
		}
	}
        return 1;
};

}  // namespace routing
