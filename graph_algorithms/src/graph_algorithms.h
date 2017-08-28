#ifndef ROUTING_GRAPH_ALGORITHMS_H
#define ROUTING_GRAPH_ALGORITHMS_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <lemon/list_graph.h>

using namespace lemon;
using namespace std;

namespace routing {

class GraphAlgorithms
{
public:
        GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<size_t>& cost, ListGraph::NodeMap<pair<size_t, size_t>>& position, size_t n, size_t m);
	~GraphAlgorithms();

        vector<size_t>* dijkstra(ListGraph::Node& source, ListGraph::Node& target);
        vector<size_t>* dijkstra(size_t source, size_t target);

        vector<size_t>* aStar(ListGraph::Node& source, ListGraph::Node& target);
        vector<size_t>* aStar(size_t source, size_t target);

        int test();

private:
        size_t heuristic(ListGraph::Node& source, ListGraph::Node& target);

	ListGraph& mGraph;
        ListGraph::EdgeMap<size_t>& mCost;
        ListGraph::NodeMap<pair<size_t, size_t>>& mPosition;
        size_t mNodesAmount, mEdgesAmount;
};

}  // namespace routing

#endif
