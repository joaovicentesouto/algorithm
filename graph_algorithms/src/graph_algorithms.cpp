#ifndef ROUTING_GRAPH_ALGORITHMS_CPP
#define ROUTING_GRAPH_ALGORITHMS_CPP

#include "./graph_algorithms.h"

using namespace lemon;
using namespace std;

namespace routing {

GraphAlgorithms::GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<size_t>& cost, ListGraph::NodeMap<pair<size_t, size_t>>& position, size_t n, size_t m) :
    mGraph(graph),
    mCost(cost),
    mPosition(position),
    mNodesAmount(n),
    mEdgesAmount(m)
{

};

GraphAlgorithms::~GraphAlgorithms()
{

};

vector<size_t>* GraphAlgorithms::dijkstra(size_t source, size_t target)
{
    if (source > mNodesAmount || target > mNodesAmount)
    {
        throw out_of_range("Index out of range!");
    }

    ListGraph::Node s = mGraph.nodeFromId(source);
    ListGraph::Node t = mGraph.nodeFromId(target);

    return dijkstra(s, t);
}

vector<size_t>* GraphAlgorithms::dijkstra(ListGraph::Node& source, ListGraph::Node& target)
{
    vector<size_t>* minimumCostPath = new vector<size_t>();
    size_t minimum, newPath;
    ListGraph::Node current;


    ListGraph::NodeMap<bool> closed(mGraph, false);
    ListGraph::NodeMap<size_t> pathCost(mGraph, static_cast<size_t>(-1));
    ListGraph::NodeMap<size_t> parents(mGraph, static_cast<size_t>(-1));

    pathCost[source] = 0;
    parents[source] = mGraph.id(source);

    while (!closed[target])
    {
        minimum = static_cast<size_t>(-1);
        for (ListGraph::NodeIt it(mGraph); it != INVALID; ++it)
        {
            if (!closed[it] && pathCost[it] < minimum)
            {
                current = it;
                minimum = pathCost[it];
            }
        }

        closed[current] = true;

        for (ListGraph::OutArcIt out(mGraph, current); out != INVALID && !closed[target]; ++out)
        {
            newPath = pathCost[current] + mCost[out];
            if (!closed[mGraph.target(out)] && (newPath < pathCost[mGraph.target(out)]))
            {
                pathCost[mGraph.target(out)] = newPath;
                parents[mGraph.target(out)] = mGraph.id(current);
            }
        }
    }

    current = target;
    while (current != source)
    {
        minimumCostPath->push_back(mGraph.id(current));
        current = mGraph.nodeFromId(parents[current]);
    }
    minimumCostPath->push_back(mGraph.id(current));

    return minimumCostPath;

};

vector<size_t>* GraphAlgorithms::aStar(size_t source, size_t target)
{
    if (source > mNodesAmount || target > mNodesAmount)
    {
        throw out_of_range("Index out of range!");
    }

    ListGraph::Node s = mGraph.nodeFromId(source);
    ListGraph::Node t = mGraph.nodeFromId(target);

    return aStar(s, t);
}

vector<size_t>* GraphAlgorithms::aStar(ListGraph::Node& source, ListGraph::Node& target)
{
    vector<size_t>* minimumCostPath = new vector<size_t>();

    ListGraph::Node current, neighbor;

    size_t openedAmount = 1, gCostAttempt, minimum;

    ListGraph::NodeMap<bool> closed(mGraph, false);
    ListGraph::NodeMap<bool> opened(mGraph, false);

    ListGraph::NodeMap<size_t> gCost(mGraph, static_cast<size_t>(-1));
    ListGraph::NodeMap<size_t> fCost(mGraph, static_cast<size_t>(-1));

    ListGraph::NodeMap<ListGraph::Node> parents(mGraph);

    opened[source] = true;
    gCost[source] = 0;
    fCost[source] = heuristic(source, target);
    parents[source] = source;

    while(openedAmount > 0)
    {
        minimum = static_cast<size_t>(-1);
        for (ListGraph::NodeIt it(mGraph); it != INVALID; ++it)
        {
            if (opened[it] && fCost[it] < minimum)
            {
                current = it;
                minimum = fCost[it];
            }
        }

        if (current == target)
        {
            break;
        }

        opened[current] = false;
        openedAmount--;
        closed[current] = true;

        for (ListGraph::OutArcIt out(mGraph, current); out != INVALID; ++out)
        {
            neighbor = mGraph.target(out);
            if (closed[neighbor])
            {
                continue;
            }

            if (!opened[neighbor])
            {
                opened[mGraph.target(out)] = true;
                openedAmount++;
            }

            gCostAttempt = gCost[current] + mCost[out];
            if (gCostAttempt >= gCost[neighbor])
            {
                continue;
            }

            parents[neighbor] = current;

            gCost[neighbor] = gCostAttempt;
            fCost[neighbor] = gCost[neighbor] + heuristic(neighbor, target);
        }
    }

    current = target;
    while (current != source)
    {
        minimumCostPath->push_back(mGraph.id(current));
        current = parents[current];
    }
    minimumCostPath->push_back(mGraph.id(current));

    return minimumCostPath;
};

size_t GraphAlgorithms::heuristic(ListGraph::Node& source, ListGraph::Node& target)
{
    return abs(mPosition[source].first - mPosition[target].first) + abs(mPosition[source].second - mPosition[target].second);
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

#endif
