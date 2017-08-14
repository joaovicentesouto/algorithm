#include <vector>
#include <lemon/list_graph.h>

using namespace lemon;
using namespace std;

namespace routing {

class GraphAlgorithms
{
public:
	GraphAlgorithms(ListGraph& graph, ListGraph::EdgeMap<int>& cost, size_t n, size_t m);
	~GraphAlgorithms();

	std::vector<std::size_t>* dijkstra(ListGraph::Node& source, ListGraph::Node& target);
	void test();

private:
	ListGraph& mGraph;
	ListGraph::EdgeMap<int>& mCost;
	size_t mAmountNodes, mAmountEdges;
};

}  // namespace routing