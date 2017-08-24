#ifndef ROUTING_GRAPH_ALGORITHMS_H
#define ROUTING_GRAPH_ALGORITHMS_H

#include <vector>
#include <stdexcept>
#include <lemon/list_graph.h>

using namespace lemon;
using namespace std;

namespace routing {

class GraphAlgorithms
{
public:
        GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<size_t>& cost, size_t n, size_t m);
	~GraphAlgorithms();

        std::vector<std::size_t>* dijkstra(ListGraph::Node& source, ListGraph::Node& target);
        std::vector<std::size_t>* dijkstra(size_t source, size_t target);
	
        int test();

private:
	ListGraph& mGraph;
        ListGraph::EdgeMap<size_t>& mCost;
        size_t mNodesAmount, mEdgesAmount;
};

}  // namespace routing

#endif
