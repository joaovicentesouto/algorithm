#include <catch.hpp>
#include <vector>
#include "../src/graph_algorithms.cpp"

using namespace routing;
using namespace lemon;
using namespace std;

namespace {
class GraphFixture {
public:
    ListGraph graph;
    ListGraph::EdgeMap<int> cost{graph};

    GraphFixture()
    {
        vector<ListGraph::Node> nodes;
        for (int i = 0; i < 10; ++i)
        {
            nodes[i] = graph.addNode();
        }

        cost[graph.addEdge(nodes[0], nodes[1])] = 2;
        cost[graph.addEdge(nodes[0], nodes[2])] = 4;
        cost[graph.addEdge(nodes[1], nodes[4])] = 6;
        cost[graph.addEdge(nodes[2], nodes[3])] = 5;
        cost[graph.addEdge(nodes[3], nodes[6])] = 2;
        cost[graph.addEdge(nodes[4], nodes[6])] = 2;
        cost[graph.addEdge(nodes[5], nodes[6])] = 1;
        cost[graph.addEdge(nodes[6], nodes[7])] = 1;
        cost[graph.addEdge(nodes[6], nodes[8])] = 8;
        cost[graph.addEdge(nodes[7], nodes[9])] = 4;
        cost[graph.addEdge(nodes[8], nodes[9])] = 1;
    }
};
}

TEST_CASE_METHOD(GraphFixture, "Teste do teste", "[tag]")
{
    //algum teste
    //routing::GraphAlgorithms algs(graph, cost, 10, 11);
    //algs.test();
    
    //REQUIRE(true);
}