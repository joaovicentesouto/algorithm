#include <catch.hpp>
#include <vector>
#include "../src/graph_algorithms.cpp"

using namespace lemon;
using namespace std;

namespace {
class GraphFixture {
public:
    ListGraph mGraph;
    ListGraph::EdgeMap<size_t> mCost;
    size_t mNodesAmount, mEdgesAmount;

    GraphFixture()
        : mCost(mGraph),
          mNodesAmount(7),
          mEdgesAmount(9)
    {
        vector<ListGraph::Node> nodes;

        for (auto i = 0; i < mNodesAmount; ++i)
        {
            nodes.push_back(mGraph.addNode());
        }

        // Adicionando arestas e ja lhes atribuindo um valor.
        mCost[mGraph.addEdge(nodes[0], nodes[1])] = 1;
        mCost[mGraph.addEdge(nodes[0], nodes[2])] = 2;
        mCost[mGraph.addEdge(nodes[1], nodes[3])] = 1;
        mCost[mGraph.addEdge(nodes[2], nodes[3])] = 3;
        mCost[mGraph.addEdge(nodes[3], nodes[4])] = 4;
        mCost[mGraph.addEdge(nodes[3], nodes[5])] = 1;
        mCost[mGraph.addEdge(nodes[3], nodes[6])] = 8;
        mCost[mGraph.addEdge(nodes[4], nodes[6])] = 5;
        mCost[mGraph.addEdge(nodes[5], nodes[6])] = 1;
    }

    ~GraphFixture()
    {

    }
};
}

TEST_CASE_METHOD(GraphFixture, "Caminho de custo mínimo 0 -> 6", "[dijkstra]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mNodesAmount, mEdgesAmount);

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
    routing::GraphAlgorithms g(mGraph, mCost, mNodesAmount, mEdgesAmount);

    vector<std::size_t> *correctWay = new vector<std::size_t>();
    correctWay->push_back(6);
    correctWay->push_back(5);
    correctWay->push_back(3);
    correctWay->push_back(2);

    REQUIRE(*correctWay == *(g.dijkstra(2, 6)));
}

TEST_CASE_METHOD(GraphFixture, "Exception test", "[dijkstra]")
{
    routing::GraphAlgorithms g(mGraph, mCost, mNodesAmount, mEdgesAmount);

    REQUIRE_THROWS(g.dijkstra(2, 20));
}
