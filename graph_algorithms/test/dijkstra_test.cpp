#include <catch.hpp>
#include <vector>
#include "../src/graph_algorithms.cpp"

using namespace lemon;
using namespace std;

namespace {
class GraphFixture {
public:
    ListGraph graph;
    ListGraph::EdgeMap<int> *cost;

    GraphFixture()
    {
        /*vector<ListGraph::Node> nodes;
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
        cost[graph.addEdge(nodes[8], nodes[9])] = 1;*/

        vector<ListGraph::Node> nodes;
        for (auto i = 0; i < 7; ++i)
        {
            nodes.push_back(graph.addNode());
        }

        cost = new ListGraph::EdgeMap<int> (graph);
        (*cost)[graph.addEdge(nodes[0], nodes[1])] = 1;
        (*cost)[graph.addEdge(nodes[0], nodes[2])] = 2;
        (*cost)[graph.addEdge(nodes[1], nodes[3])] = 1;
        (*cost)[graph.addEdge(nodes[2], nodes[3])] = 3;
        (*cost)[graph.addEdge(nodes[3], nodes[4])] = 4;
        (*cost)[graph.addEdge(nodes[3], nodes[5])] = 1;
        (*cost)[graph.addEdge(nodes[3], nodes[6])] = 8;
        (*cost)[graph.addEdge(nodes[4], nodes[6])] = 5;
        (*cost)[graph.addEdge(nodes[5], nodes[6])] = 1;
    }
};
}

TEST_CASE_METHOD(GraphFixture, "Caminho de custo mínimo 0 -> 6", "[dijkstra]")
{
    routing::GraphAlgorithms g(graph, *cost, 7, 9);

    vector<std::size_t> *correctWay = new vector<std::size_t>();
    correctWay->push_back(6);
    correctWay->push_back(5);
    correctWay->push_back(3);
    correctWay->push_back(1);
    correctWay->push_back(0);

    REQUIRE(*correctWay == *(g.dijkstra(0, 6)));
}

TEST_CASE_METHOD(GraphFixture, "Caminho de custo mínimo 2 -> 6", "[dijkstra]")
{
    routing::GraphAlgorithms g(graph, *cost, 7, 9);

    vector<std::size_t> *correctWay = new vector<std::size_t>();
    correctWay->push_back(6);
    correctWay->push_back(5);
    correctWay->push_back(3);
    correctWay->push_back(2);

    REQUIRE(*correctWay == *(g.dijkstra(2, 6)));
}
